/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:34:04 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 17:34:05 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        void setType(std::string type);
        const std::string &getType() const;
};



#endif