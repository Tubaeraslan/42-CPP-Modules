/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:12:38 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/16 15:12:39 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap a("Tuba");
    a.attack("enemy");
    a.takeDamage(5);
    a.beRepaired(3);
    std::cout << std::endl;

    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap b("Kevser");
    b.attack("monster");
    b.takeDamage(20);
    b.beRepaired(10);
    b.guardGate();
    std::cout << std::endl;

    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap c("Eraslan");
    c.attack("boss");
    c.takeDamage(50);
    c.beRepaired(25);
    c.highFivesGuys();
    std::cout << std::endl;

    std::cout << "=== Destruction sequence ===" << std::endl;
    return 0;
}
