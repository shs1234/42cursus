/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:38:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/09/14 13:47:47 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static void display_form(std::string str)
{
	std::string temp;
	if (str.size() > 10)
	{
		temp = str.substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << temp;
	}
	else
		std::cout << std::right << std::setw(10) << str;
}

void Contact::display(int i)
{
	std::cout << "|";
	std::cout << "         " << i + 1;
	std::cout << "|";
	display_form(this->field[0]);
	std::cout << "|";
	display_form(this->field[1]);
	std::cout << "|";
	display_form(this->field[2]);
	std::cout << "|";
	std::cout << std::endl;
}

void Contact::display_perline()
{
	std::cout << "first name : " << field[0] << std::endl;
	std::cout << "last name : " << field[1] << std::endl;
	std::cout << "nickname : " << field[2] << std::endl;
	std::cout << "phone number : " << field[3] << std::endl;
	std::cout << "darkest secret : " << field[4] << std::endl;
}

void Contact::setdata(std::string *field)
{
	for (int i = 0; i < 5; i++)
		this->field[i] = field[i];
}
