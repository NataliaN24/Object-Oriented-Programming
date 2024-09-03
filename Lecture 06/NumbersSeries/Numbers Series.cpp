//Създайте клас NumberSeries, който моделира работата с числова редица.В конструктора на класа ще приемате
//цяло число - начална стойност на редицата(a_0) и указател към функция на преход, приемаща цяло число и връщаща цяло число(a_i = f(a_i - 1)).
//
//Трябва да имате следните функционалности :
//
//Генериране на i - то число от редицата.
//Проверка дали подадено число е част от редицата.
//Setter - и за нова начална стойност и нова функция на преход.
//Генерирането на стойности трябва да бъде оптимизирано откъм скорост :
//
//За коректна работа с фунцкионалността за генериране на i - то по ред число, трябва да поддържате динамичен масив в класа, в
//който да пазите досега генерираните стойности.
//Ако числото вече е било генерирано, трябва да го върнете като резултат без да го генерирате повторно.
//Ако числото го няма в масива, генерирайте и добавете към масива всички числа, които липсват до a_i в редицата и върнете
//генерираната стойност.
//Ако в масива няма достатъчно място, за да се съхранят новите стойности, преоразмерете го по подходящ начин.
//При set - ване на нова начална стойност или функция на преход, трябва да изтривате динамичния масив и да започвате процеса на запазване отначало.
//Помислете как трябва да се handle - не коректно копирането на обекти от вашия клас.

#include <iostream>
#include <stdexcept>  

class NumberSeries {
	int* series;
    size_t capacity;                  
    size_t size;                      
    int startValue;                   
    int (*transitionFunc)(int);

    void copyFrom(const NumberSeries& other) {
        startValue = other.startValue;
        transitionFunc = other.transitionFunc;
        size = other.size;
        capacity = other.capacity;
        series = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            series[i] = other.series[i];
        }
    }

    void moveFrom(NumberSeries&& other) noexcept {
        startValue = other.startValue;
        transitionFunc = other.transitionFunc;
        series = other.series;
        capacity = other.capacity;
        size = other.size;
        other.series = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    void free() {
        delete[] series;
    }

    void resize() {
        capacity *= 2;
        int* newSeries = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            newSeries[i] = series[i];
        }
        delete[] series;
        series = newSeries;
    }

    void ensureCapacity() {
        if (size >= capacity) {
            resize();
        }
    }
public:
    NumberSeries(int startValue, int(*func)(int)) :startValue(startValue), transitionFunc(func), size(0), capacity(2) {
        series = new int[capacity];
        series[size++] = startValue;
    }
    NumberSeries(const NumberSeries& other) {
        copyFrom(other);
    }

    NumberSeries(NumberSeries&& other) noexcept {
        moveFrom(std::move(other));
    }

    NumberSeries& operator=(const NumberSeries& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    NumberSeries& operator=(NumberSeries&& other) noexcept {
        if (this != &other) {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    ~NumberSeries() {
        free();
    }
    
    int getNthValue(size_t n)
    {
        if (n < size)
        {
            return series[n];
        }
        while (n >= size)
        {
            ensureCapacity();
            series[size++] = transitionFunc(series[size - 1]);
        }
        return series[n];
    }
    bool isInSeries(int value)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (series[i] == value)
            {
                return true;
            }
        }

        while (series[size - 1] < value)
        {
            ensureCapacity();
            series[size] = transitionFunc(series[size - 1]);
            if (series[size] == value) {
                return true;
            }
            size++;
        }
        return false;
    }
    void setStartValue(int newStartValue) {
        startValue = newStartValue;
        free(); 
        size = 0;
        capacity = 2;
        series = new int[capacity];
        series[size++] = startValue;
    }

    void setTransitionFunc(int(*newFunc)(int)) {
        transitionFunc = newFunc;
        free(); 
        size = 0;
        capacity = 2;
        series = new int[capacity];
        series[size++] = startValue;
    }

};

int transition(int n) {
    return n * 2; 
}

int main() {
    NumberSeries series(1, transition); 


    for (size_t i = 0; i < 10; ++i) {
        std::cout << "Value at index " << i << ": " << series.getNthValue(i) << std::endl;
    }


    std::cout << "Is 16 in the series? " << (series.isInSeries(16) ? "Yes" : "No") << std::endl;

    series.setStartValue(3);
    series.setTransitionFunc([](int n) { return n + 5; }); 

    for (size_t i = 0; i < 10; ++i) {
        std::cout << "Value at index " << i << ": " << series.getNthValue(i) << std::endl;
    }

    return 0;
}
