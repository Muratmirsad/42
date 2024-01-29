#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    Animal* test[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

    for (int index = 0; index < 4; index++)
    {
        test[index]->makeSound();
    }

    return 0;
}