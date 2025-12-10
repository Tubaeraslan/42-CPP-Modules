/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:12:30 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/16 15:12:31 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << ClapTrap::name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other) {
    std::cout << "FragTrap " << ClapTrap::name << " constructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << ClapTrap::name << " destructed." << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << ClapTrap::name << " is requesting a high five!" << std::endl;
}
