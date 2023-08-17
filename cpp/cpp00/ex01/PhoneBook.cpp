/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:02:28 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/17 13:15:10 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->count = 0;
}

void PhoneBook::add()
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;
	if (this->index == 8)
		this->index = 0;
	std::cout << "first name : ";
	std::getline(std::cin, fn);
	std::cout << "last name : ";
	std::getline(std::cin, ln);
	std::cout << "nickname : ";
	std::getline(std::cin, nn);
	std::cout << "phone number : ";
	std::getline(std::cin, pn);
	std::cout << "darkest secret : ";
	std::getline(std::cin, ds);
	this->contact[this->index].setdata(fn, ln, nn, pn, ds);
	if (this->count < 8)
		this->count++;
	this->index++;
}

void PhoneBook::search()
{
	int	index;

	for (int i = 0; i < this->count; i++)
	{
		std::cout << i + 1 << " : ";
		this->contact[i].display();
		std::cout << std::endl;
		// 형식 바꿀것.
	}
	std::cout << "select index : ";
	std::cin >> index;
	if (index < 1 || index > count)
		std::cout << "error" << std::endl;
	else
	{
		this->contact[index - 1].display();
		std::cout << std::endl;
		// 한줄에 하나씩으로 바꿀것.
	}
}

void PhoneBook::invalidcommand()
{
	std::cout << "invalid command" << std::endl;
}
