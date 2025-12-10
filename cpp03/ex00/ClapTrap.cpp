/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:11:47 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/16 15:11:48 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
        std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
        std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
        std::cout << "ClapTrap " << name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack, it's out of hit points!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }

    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage! "
              << "(HP: " << hitPoints << ", Energy: " << energyPoints << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already out of hit points!" << std::endl;
        return;
    }

    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;

    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! (HP left: " << hitPoints
              << ", Energy: " << energyPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired, it's out of hit points!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy left to repair!" << std::endl;
        return;
    }

    --energyPoints;
    hitPoints += amount;

    std::cout << "ClapTrap " << name << " repairs itself for " << amount
              << " hit points! (HP: " << hitPoints
              << ", Energy: " << energyPoints << ")" << std::endl;
}
