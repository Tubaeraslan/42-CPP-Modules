/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:22:39 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 13:22:40 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();

    void announce() const;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif