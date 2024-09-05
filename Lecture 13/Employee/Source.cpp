#include <iostream>
#include <stdexcept>
#include"MyString.h"

class Employee
{
protected:
	MyString name;
	unsigned int age;
	double salary;
public:
    Employee() = default;
	Employee(const MyString&name,unsigned int age, double wage):name(name),
		age(age),salary(wage){}

	const MyString& getName()const
	{
		return name;
	}
	unsigned int getAge()const
	{
		return age;
	}
	double getWage()const
	{
		return salary;
	}
   virtual Employee* clone()const = 0;
	virtual ~Employee() = default;
	virtual  void print()const = 0;
};

class Worker : virtual public Employee
{
	unsigned int  months;
public:
	Worker(const MyString& name, unsigned int age, double wage, unsigned int months) :
		Employee(name, age, wage)
	{
		this->months = months;
	}

    Worker(unsigned int months):months(months){}

	unsigned int getMonths()const
	{
		return months;
	}
	void print()const override
	{
		std::cout << "Worker: " << name << ", Age: " << age
			<< ", Salary: $" << salary
			<< ", Months Worked: " << months << std::endl;
	}
    Employee* clone()const
    {
        return new Worker(*this);
    }
};

class Trainee :  virtual public Employee
{
	int daysRemaining;

public:
	Trainee(const MyString& name, int age, double salary, int daysRemaining)
		: Employee(name, age, salary), daysRemaining(daysRemaining) {}

    Trainee(int days) :daysRemaining(days) {}

	void print() const override {
		std::cout << "Trainee: " << name << ", Age: " << age
			<< ", Salary: $" << salary
			<< ", Days Remaining: " << daysRemaining << std::endl;
	}

	int getDaysRemaining() const { return daysRemaining; }
    Employee* clone()const override
    {
        return new Trainee(*this);
    }
};

class PaidTrainee : public Worker, public Trainee {
	unsigned int  rating;

public:
    PaidTrainee(const MyString& name, unsigned int age, double salary, unsigned int months, int daysRemaining, unsigned int rating)
        : Employee(name,age,salary),Worker(months), Trainee(daysRemaining)
    {
        setRating(rating);
    }

	unsigned int getRating() const 
    {
        return rating;
    }

    void setRating(unsigned int rating)
    {
        if (rating >= 0 && rating <= 100) {
            this->rating = rating;
        }
    }
    Employee* clone()const override
    {
        return new PaidTrainee(*this);
    }
	void print() const override {
		
		std::cout << "Paid Trainee: " << Worker::name.c_str() << ", Age: " << age
			<< ", Salary: $" << salary
			<< ", Months Worked: " << getMonths()
			<< ", Days Remaining: " << getDaysRemaining()
			<< ", Rating: " << rating << std::endl;
	}
};

class Company 
{
    Employee** employees;
    size_t count;
    size_t capacity;

    void resize() {
        capacity *= 2;
        Employee** newEmployees = new Employee * [capacity];
        for (size_t i = 0; i < count; ++i) {
            newEmployees[i] = employees[i];
        }
        delete[] employees;
        employees = newEmployees;
    }
    void copyFrom(const Company& other)
    {
        employees = new Employee * [other.capacity];
        capacity = other.capacity;
        count = other.count;

        for (int i = 0; i < count; i++)
        {
            employees[i] = other.employees[i]->clone();
        }
    }
    void moveFrom(Company&& other)
    {
        employees = other.employees;
        count = other.count;
        capacity = other.capacity;

        other.employees = nullptr;
        other.count = 0;
        other.capacity = 0;
    }

    void free()
    {
        for (size_t i = 0; i < count; ++i) {
            delete employees[i];
        }
        delete[] employees;
    }

public:
    Company()
    {
        capacity = 15;
        count = 0;
        employees = new Employee * [capacity];
    }
    Company(const Company& other)
    {
        copyFrom(other);
    }
    Company(Company&& other)noexcept
    {
        moveFrom(std::move(other));
    }
    Company& operator=(const Company& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    Company& operator=( Company&& other)noexcept
    {
        if (this != &other)
        {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    ~Company() 
    {
        free();
    }

    Company(size_t newCap)
    {
        capacity = newCap;
        employees = new Employee * [capacity];
    }

    void sortCompany()
    {
        for (int i = 0; i < count-1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < count; j++)
            {
                if (employees[j]->getWage() < employees[minIndex]->getWage())
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                std::swap(employees[i], employees[minIndex]);
            }
        }
    }


    void addWorker(const MyString& name, unsigned int age, double salary, unsigned int months) {
        if (count == capacity) {
            resize();
        }
        employees[count++] = new Worker(name, age, salary, months);
        sortCompany();
        
    }

    void addTrainee(const MyString& name, unsigned int age, double salary, int days) {
        if (count == capacity) {
            resize();
        }
        employees[count++] = new Trainee(name, age, salary, days);
        sortCompany();
    }

    void addPaidTrainee(const MyString& name, unsigned int age, double salary, unsigned int months, int days, double rating) {
        if (count == capacity) {
            resize();
        }
        employees[count++] = new PaidTrainee(name, age, salary, months, days, rating);
        sortCompany();
    }

    double averageSalary() const 
    {
        double average = 0;
        for (int i = 0; i < count; i++)
        {
            average += employees[i]->getWage();
        }
       return  average /= count;
       
    }
    bool binarySearch(int left, int right, double x)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (employees[mid]->getWage() == x)
            {
                return true;
            }
            else if (employees[mid]->getWage() < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }

    bool twoSum(double val)
    {
        sortCompany();
        for (int i = 0; i < count; i++)
        {
            double diff = val - employees[i]->getWage();
            if (binarySearch(i+1, count - 1, diff)) {
                return true;
                
            }
            
        }
        return false;

    }

    void printAll() const {
        for (int i = 0; i < count; i++)
        {
            employees[i]->print();
        }
      
    }
};

int main() {
    MyString name1("John");
    MyString name2("Alice");
    MyString name3("Bob");

    Company myCompany;

    myCompany.addWorker(name1, 30, 3000, 24);
    myCompany.addTrainee(name2, 22, 1500, 120);
    myCompany.addPaidTrainee(name3, 25, 2500, 12, 60, 85);

    std::cout << "All employees:\n";
    myCompany.printAll();

    std::cout << "\nAverage Salary: " << myCompany.averageSalary() << std::endl;

    std::cout << "\nTwo sum (4500): " << (myCompany.twoSum(4500) ? "Yes" : "No") << std::endl;

    return 0;
}