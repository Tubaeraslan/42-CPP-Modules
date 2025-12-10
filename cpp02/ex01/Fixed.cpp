/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:58:24 by teraslan          #+#    #+#             */
/*   Updated: 2025/10/29 13:42:31 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point_value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point_value = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixed_point_value = other.fixed_point_value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(fixed_point_value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return fixed_point_value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}