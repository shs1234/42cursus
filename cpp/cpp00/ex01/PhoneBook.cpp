/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:02:28 by hoseoson          #+#    #+#             */
/*   Updated: 2023/09/14 13:05:49 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), count(0)
{
}

void getfield(std::string fieldname, std::string &field)
{
	while (1)
	{
		std::cout << fieldname << " : ";
		std::getline(std::cin, field);
		if (std::cin.eof())
			exit(0);
		if (std::cin.good() && field.length() > 0)
			return ;
		std::cin.clear();
	}
}

void PhoneBook::add()
{
	std::string field[5];
	
	getfield("first name", field[0]);
	getfield("last name", field[1]);
	getfield("nickname", field[2]);
	getfield("phone number", field[3]);
	getfield("darkest secret", field[4]);
	this->contact[this->index].setdata(field);
	if (this->count < 8)
		this->count++;
	this->index++;
	if (this->index == 8)
		this->index = 0;
}

void PhoneBook::search()
{
	int index;

	if (this->count == 0)
	{
		std::cout << "no data" << std::endl;
		return ;
	}
	for (int i = 0; i < this->count; i++)
		this->contact[i].display(i);
	while (1)
	{
		std::cout << "select index : ";
		std::cin >> index;
		if (std::cin.eof())
			exit(0);
		if (std::cin.good() && index > 0 && index <= count)
			break;
		std::cout << "invalid index" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	this->contact[index - 1].display_perline();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
