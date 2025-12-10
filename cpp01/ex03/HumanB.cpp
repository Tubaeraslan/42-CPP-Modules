/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:33:50 by teraslan          #+#    #+#             */
/*   Updated: 2025/10/05 13:12:41 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}


HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (this->weapon)
        std::cout << this->name << " attacks with their "
                  << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}