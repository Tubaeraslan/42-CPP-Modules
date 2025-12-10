/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:50:38 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/15 13:48:51 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	Contact();
	~Contact();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(const std::string &str);
	void setLastName(const std::string &str);
	void setNickname(const std::string &str);
	void setPhoneNumber(const std::string &str);
	void setDarkestSecret(const std::string &str);
};

