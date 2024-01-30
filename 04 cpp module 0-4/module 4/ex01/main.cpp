/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:14:53 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/30 18:15:10 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    Animal *test[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    Dog selam;
    Dog _dog = selam;
    Dog _dog2(selam);
    Cat _cat;
    Cat _cat2(_cat);

    for (int index = 0; index < 4; index++)
    {
        test[index]->makeSound();
    }
    selam.makeSound();
    _dog.makeSound();
    _dog2.makeSound();
    _cat2.makeSound();

    return 0;
}