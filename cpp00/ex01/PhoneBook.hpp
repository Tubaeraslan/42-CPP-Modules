/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:46:21 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/15 14:02:42 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contact_index;
	int total;
public:
	PhoneBook();
	~PhoneBook();

	Contact getContact(int index) const;
	void addContact();
	void searchContact();
};

