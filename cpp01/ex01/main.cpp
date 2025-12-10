/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:48:54 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 13:48:55 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *horde;
    int N = 5;
    horde = zombieHorde(N, "Zed");
    for (int i = 0; i < N; i++){
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
