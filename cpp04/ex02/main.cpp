/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:49:51 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/25 15:57:58 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	
    Animal* animals[2];

    animals[0] = new Dog();
    animals[1] = new Cat();

    std::cout << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
        delete animals[i];

    return 0;
}