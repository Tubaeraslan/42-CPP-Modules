/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:33:47 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 17:33:48 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
    std::string name;
    Weapon &weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void attack();
};

#endif