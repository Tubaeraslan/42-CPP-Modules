/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:47:00 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/25 14:26:06 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment called" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}
