/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:02:28 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/21 03:08:30 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->count = 0;
}

int PhoneBook::add()
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;
	if (this->index == 8)
		this->index = 0;
	std::cout << "first name : ";
	if (!std::getline(std::cin, fn))
		return (1);
	std::cout << "last name : ";
	if (!std::getline(std::cin, ln))
		return (1);
	std::cout << "nickname : ";
	if (!std::getline(std::cin, nn))
		return (1);
	std::cout << "phone number : ";
	if (!std::getline(std::cin, pn))
		return (1);
	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, ds))
		return (1);
	this->contact[this->index].setdata(fn, ln, nn, pn, ds);
	if (this->count < 8)
		this->count++;
	this->index++;
	return (0);
}

int PhoneBook::search()
{
	int index;

	for (int i = 0; i < this->count; i++)
	{
		std::cout << i + 1;
		this->contact[i].display();
	}
	std::cout << "select index : ";
	std::cin >> index;
	if (!std::cin.good() || index < 1 || index > count)
	{
		if (std::cin.eof())
			return (1);
		std::cout << "invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (0);
	}
	this->contact[index - 1].display_perline();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (0);
}
