#include <iostream>
#include "HeterogeneousContainer.hpp" 
#include "polymorphic_ptr.hpp"        

class Animal {
public:
    virtual void speak() const = 0;
    virtual Animal* clone() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
    std::string name;
public:
    Dog(std::string n = "Dog") : name(std::move(n)) {}
    void speak() const override { std::cout << "Woof! I am " << name << '\n'; }
    Dog* clone() const override { return new Dog(*this); }
};

class Cat : public Animal {
    int age;
public:
    Cat(int a = 2) : age(a) {}
    void speak() const override { std::cout << "Meow! I'm " << age << " years old.\n"; }
    Cat* clone() const override { return new Cat(*this); }
};

int main() {
    HeterogeneousContainer<Animal> zoo;

    zoo.add(Dog("Rex"));
    zoo.add(Cat(5));
    zoo.add(Dog("Buddy"));

    std::cout << "== Speak via operator[] ==\n";
    for (size_t i = 0; i < zoo.getSize(); ++i)
        zoo[i].speak(); // използва **data[i]

    std::cout << "\n== Speak via at() ==\n";
    for (size_t i = 0; i < zoo.getSize(); ++i)
        zoo.at(i).speak();

    std::cout << "\n== Copy container ==\n";
    HeterogeneousContainer<Animal> copyZoo = zoo;

    copyZoo.add(Cat(9));

    for (size_t i = 0; i < copyZoo.getSize(); ++i)
        copyZoo[i].speak();

    std::cout << "\n== Original zoo unchanged ==\n";
    for (size_t i = 0; i < zoo.getSize(); ++i)
        zoo[i].speak();

    return 0;
}
