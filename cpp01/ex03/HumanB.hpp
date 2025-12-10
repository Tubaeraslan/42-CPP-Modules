/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:33:54 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 17:33:55 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB(std::string name);
    ~HumanB();

    void attack();
    void setWeapon(Weapon &weapon);
};

#endif