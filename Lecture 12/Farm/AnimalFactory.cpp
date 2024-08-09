#include "AnimalFactory.h"

Animal* animalFactory(animalType type)
{
    switch (type)
    {
    case animalType::dog:
            return new Dog();
    case animalType::cat:
        return new Cat();
    case animalType::cow:
        return new Cow();
    }
    return nullptr;
}
