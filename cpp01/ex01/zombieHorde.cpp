/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:49:51 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 13:49:52 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }

    Zombie *zombieHorde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        zombieHorde[i] = Zombie(name);
    }
    return zombieHorde;
}