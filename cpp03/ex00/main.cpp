/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:11:53 by teraslan          #+#    #+#             */
/*   Updated: 2025/11/16 15:11:54 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap tuba("Tuba");
    ClapTrap eraslan("Eraslan");

    std::cout << std::endl;

    // Round 1
    tuba.attack("Eraslan");
    eraslan.takeDamage(3);

    std::cout << std::endl;

    // Round 2
    eraslan.attack("Tuba");
    tuba.takeDamage(4);

    std::cout << std::endl;

    // Round 3
    tuba.beRepaired(2);
    eraslan.attack("Tuba");
    tuba.takeDamage(5);

    std::cout << std::endl;

    // Round 4
    tuba.attack("Eraslan");
    eraslan.takeDamage(2);

    std::cout << std::endl;

    // Round 5 
    tuba.beRepaired(3);
    eraslan.beRepaired(1);

    std::cout << std::endl;

    // Round 6
    tuba.attack("Eraslan");
    eraslan.takeDamage(3);
    eraslan.attack("Tuba");
    tuba.takeDamage(4);

    std::cout << std::endl;

    std::cout << "=== Battle Finished ===" << std::endl;

    return 0;
}
