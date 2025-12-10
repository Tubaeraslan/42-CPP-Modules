/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:49:41 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 13:49:42 by teraslan         ###   ########.fr       */
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
    Zombie();
	Zombie(std::string name);
	~Zombie();

    void announce() const;
};

Zombie *zombieHorde(int N, std::string name);

#endif