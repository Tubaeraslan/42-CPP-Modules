/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:07:29 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/25 13:22:50 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}
