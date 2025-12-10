/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:27:57 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/25 14:15:17 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal copy assignment called" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "* animal sound *" << std::endl;
}

