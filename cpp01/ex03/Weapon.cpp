/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:34:01 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 17:34:02 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
    Weapon::setType(type);
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
    this->type=type;
}

const std::string &Weapon::getType() const
{
    return(this->type);
}