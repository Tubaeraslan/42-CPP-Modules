/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:02:57 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/08 15:13:53 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::getFirstName(void) const
{
	return this->firstName;
}

std::string Contact::getLastName(void) const
{
	return this->lastName;
}

std::string Contact::getNickname(void) const
{
	return this->nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->darkestSecret;
}

void Contact::setFirstName(const std::string &str)
{
	this->firstName = str;
}

void Contact::setLastName(const std::string &str)
{
	this->lastName = str;
}

void Contact::setNickname(const std::string &str)
{
	this->nickname = str;
}

void Contact::setPhoneNumber(const std::string &str)
{
	this->phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string &str)
{
	this->darkestSecret = str;
}