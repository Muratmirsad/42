#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;

    // i->makeSound();
    // j->makeSound();

    // delete j;
    // delete i;

    Animal* test[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

    for (int index = 0; index < 4; index++)
    {
        test[index]->makeSound();
    }

    system("leaks program");

    return 0;
}