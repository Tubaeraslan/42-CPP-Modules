/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:57:04 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 17:57:05 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    Harl();
    ~Harl();
    void complain( std::string level );
};

#endif