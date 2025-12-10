/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:57:08 by teraslan          #+#    #+#             */
/*   Updated: 2025/10/11 15:19:39 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    std::cout << "Testing Harl complaints:" << std::endl << std::endl;

    std::cout << "[DEBUG]" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "[INFO]" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "[WARNING]" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "[ERROR]" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "[UNKNOWN LEVEL]" << std::endl;
    harl.complain("TUBA");
    std::cout << std::endl;

    std::cout << "All tests finished!" << std::endl;

    return 0;
}
