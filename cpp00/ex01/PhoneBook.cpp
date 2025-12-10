/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:14:00 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/25 14:53:15 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	this->contact_index = 0;
	this->total = 0;
}
PhoneBook::~PhoneBook(void)
{
	
}

Contact	PhoneBook::getContact(int index) const
{
	return (this->contacts[index % 8]);
}

int isBlank(const std::string &s)
{
    return s.std::string::find_first_not_of(" \t\n\r\f\v") == std::string::npos;
}

void PhoneBook::addContact(void)
{
    std::string input;

    while (true) {
        std::cout << "First Name: ";
        if (!std::getline(std::cin, input)){
			std::cout << "\nExiting..." << std::endl;
			std::exit(0);
		}
        if (!isBlank(input))
        	break;
    }
    contacts[this->contact_index].setFirstName(input);

    while (true) {
        std::cout << "Last Name: ";
        if (!std::getline(std::cin, input)){
			std::cout << "\nExiting..." << std::endl;
			std::exit(0);
		}
        if (!isBlank(input))
        	break;
    }
    contacts[this->contact_index].setLastName(input);

    while (true) {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, input)){
			std::cout << "\nExiting..." << std::endl;
			std::exit(0);
		}
        if (!isBlank(input))
        	break;
    }
    contacts[this->contact_index].setNickname(input);

    while (true) {
        std::cout << "Phone Number: ";
        if (!std::getline(std::cin, input)){
			std::cout << "\nExiting..." << std::endl;
			std::exit(0);
		}
        if (!isBlank(input)){
			bool check_digit = true;
			size_t j = 0;
			while (j < input.std::string::length())
			{
				if (!std::isdigit(input[j]))
				{
					check_digit = false;
					break;
				}
				j++;
			}
			if (check_digit)
			{
				contacts[this->contact_index].setPhoneNumber(input);
				break;
			}
			else
			{
            	std::cout << "Phone number must contain only digits." << std::endl;
        	}
		}
    }

    while (true) {
        std::cout << "Darkest Secret: ";
        if (!std::getline(std::cin, input)){
			std::cout << "\nExiting..." << std::endl;
			std::exit(0);
		}
        if (!isBlank(input))
        	break;
    }
    contacts[this->contact_index].setDarkestSecret(input);

    this->contact_index = (this->contact_index + 1) % 8;  
    if (this->total < 8)
        this->total++;
}

std::string formatField(const std::string &str) {
    if (str.std::string::length() > 10)
        return str.std::string::substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::searchContact(void)
{
	int i;
	int index;

	if (this->total == 0)
    {
        std::cout << "No contacts available. Add a contact first." << std::endl;
        return;
    }
	i = 0;
	std::cout << "|"
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
	while (i < total)
    {
        std::cout << "|"
                  << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
        i++;
    }
	std::string input;
	while (true)
    {
        std::cout << "Enter index: ";
        if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting..." << std::endl;
			std::exit(0);
		}
		if (input.empty())
		{
			std::cout << "Invalid input. Enter a number." << std::endl;
			continue;
		}
        bool valid = true;
        size_t j = 0;
		while (j < input.length())
		{
			if (!std::isdigit(input[j]))
			{
				valid = false;
				break;
			}
			j++;
		}
        if (valid)
            index = std::atoi(input.c_str());
        else
        {
            std::cout << "Invalid input. Enter a number." << std::endl;
            continue;
        }
        if (index >= 0 && index < total)
            break;
        else
            std::cout << "Invalid index. Try again." << std::endl;
    }
	if (index >= 0 && index < total)
	{
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << "Invalid index" << std::endl;
	}
}

int main()
{
	PhoneBook pb;
	Contact c;
	std::string input;
	while(true)
	{
		std::cout << "Enter command(ADD - SEARCH - EXIT) : ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting..." << std::endl;
			break;
		}
		if (input.std::string::empty() || isBlank(input))
    		continue;
		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Unknown command" << std::endl;
	}
	return 0;
}
