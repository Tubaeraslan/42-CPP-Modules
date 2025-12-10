/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:12:13 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/16 15:12:14 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap() {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << ClapTrap::name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other) {
    std::cout << "ScavTrap " << ClapTrap::name << " constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << ClapTrap::name << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " can't attack, it's out of hit points!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }

    --energyPoints;
    std::cout << "ScavTrap " << name << " fiercely attacks " << target
              << ", causing " << attackDamage << " points of damage! "
              << "(HP: " << hitPoints << ", Energy: " << energyPoints << ")" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << ClapTrap::name << " is now in Gate keeper mode." << std::endl;
}
