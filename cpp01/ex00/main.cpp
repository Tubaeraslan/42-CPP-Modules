/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:22:22 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 13:22:24 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie1 = newZombie("Zombie1");
    Zombie *zombie2 = newZombie("Zombie2");

    zombie1->announce();
    zombie2->announce();

    delete zombie1;
    delete zombie2;

    randomChump("RandomChump");

    return 0;
}
