/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:49:51 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/25 15:55:57 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const int N = 6;
	Animal* animals[N];

	for (int i = 0; i < N; ++i) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- sounds ---" << std::endl;
	for (int i = 0; i < N; ++i)
		animals[i]->makeSound();

	std::cout << "\n--- deleting animals ---" << std::endl;
	for (int i = 0; i < N; ++i)
		delete animals[i];

	std::cout << "\n--- deep copy test ---" << std::endl;
	Dog* d1 = new Dog();
	d1->getBrain()->setIdea(0, "Chase the mailman");
	Dog* d2 = new Dog(*d1);

	std::cout << "d1 idea[0]: " << d1->getBrain()->getIdea(0) << std::endl;
	std::cout << "d2 idea[0]: " << d2->getBrain()->getIdea(0) << std::endl;

	d1->getBrain()->setIdea(0, "Eat the bone");
	std::cout << "after changing d1" << std::endl;
	std::cout << "d1 idea[0]: " << d1->getBrain()->getIdea(0) << std::endl;
	std::cout << "d2 idea[0]: " << d2->getBrain()->getIdea(0) << std::endl;

	delete d1;
	delete d2;

	return 0;
}