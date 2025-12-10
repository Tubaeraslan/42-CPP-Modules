/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:47:45 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/25 14:26:07 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Cat copy assignment called" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}

