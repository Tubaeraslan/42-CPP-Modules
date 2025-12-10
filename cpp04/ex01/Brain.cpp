/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:30:00 by assistant         #+#    #+#             */
/*   Updated: 2025/11/25 15:30:00 by assistant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; ++i)
        ideas[i] = "";
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy assignment called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx >= 0 && idx < 100)
        ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const {
    if (idx >= 0 && idx < 100)
        return ideas[idx];
    return std::string();
}
