/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:12:43 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/16 15:12:44 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("Default_ScavTrap") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed (default)." << std::endl;
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

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << ClapTrap::name << " destructed." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << ClapTrap::name << " is now in Gate keeper mode." << std::endl;
}
