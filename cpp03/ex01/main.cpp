/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:12:07 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/16 15:12:08 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "---- Creating ScavTraps ----" << std::endl;
    ScavTrap tuba("Tuba");
    ScavTrap eraslan("Eraslan");

    std::cout << "\n---- Battle Start ----" << std::endl;

    // Round 1
    tuba.attack("Eraslan");
    eraslan.takeDamage(20);

    eraslan.attack("Tuba");
    tuba.takeDamage(20);

    std::cout << std::endl;

    // Round 2
    tuba.beRepaired(10);
    eraslan.attack("Tuba");
    tuba.takeDamage(20);

    std::cout << std::endl;

    // Round 3
    tuba.attack("Eraslan");
    eraslan.takeDamage(20);

    eraslan.guardGate();

    std::cout << "\n---- Game Over ----" << std::endl;
    return 0;
}
