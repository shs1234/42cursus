/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:02:28 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/20 14:32:01 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	putstrendl(std::string str)
{
	std::cout << str << std::endl;
}

void	putstr(std::string str)
{
	std::cout << str;
}

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->count = 0;
}


// std::string str_input()
// {
// 	std::string str;
	
// }

void PhoneBook::add()
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;
	if (this->index == 8)
		this->index = 0;
	putstr("first name : ");
	if (!std::getline(std::cin, fn))
	{
		std::cin.clear();
		std::cin.ignore();
	}
	putstr("last name : ");
	std::getline(std::cin, ln);
	putstr("nickname : ");
	std::getline(std::cin, nn);
	putstr("phone number : ");
	std::getline(std::cin, pn);
	putstr("darkest secret : ");
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
	putstr("select index : ");
	std::cin >> index;
	if (!std::cin.good() || index < 1 || index > count)
	{
		putstrendl("Invalid input.");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	this->contact[index - 1].display();
	std::cout << std::endl;
	// 한줄에 하나씩으로 바꿀것.
}
