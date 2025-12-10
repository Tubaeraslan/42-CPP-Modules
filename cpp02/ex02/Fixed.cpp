/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:58:36 by teraslan          #+#    #+#             */
/*   Updated: 2025/10/29 15:40:32 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixed_point_value(0)
{
}

Fixed::Fixed(const int value)
{
    fixed_point_value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    fixed_point_value = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        this->fixed_point_value = other.fixed_point_value;
    }
    return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
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

bool Fixed::operator>(const Fixed& other) const {
	return fixed_point_value > other.fixed_point_value; 
}
bool Fixed::operator<(const Fixed& other) const {
	return fixed_point_value < other.fixed_point_value;
}
bool Fixed::operator>=(const Fixed& other) const {
	return fixed_point_value >= other.fixed_point_value;
}
bool Fixed::operator<=(const Fixed& other) const {
	return fixed_point_value <= other.fixed_point_value;
}
bool Fixed::operator==(const Fixed& other) const {
	return fixed_point_value == other.fixed_point_value;
}
bool Fixed::operator!=(const Fixed& other) const {
	return fixed_point_value != other.fixed_point_value;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++fixed_point_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++fixed_point_value;
    return temp;
}

Fixed& Fixed::operator--() {
    --fixed_point_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --fixed_point_value;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}