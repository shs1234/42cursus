/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:38:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/21 03:08:34 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static void display_form(std::string str)
{
	std::string temp;
	if (str.size() > 10)
	{
		temp = str.substr(0, 9) + ".";
		std::cout << std::left << std::setw(10) << temp;
	}
	else
		std::cout << std::left << std::setw(10) << str;
}

void Contact::display()
{
	std::cout << "|";
	display_form(this->fn);
	std::cout << "|";
	display_form(this->ln);
	std::cout << "|";
	display_form(this->nn);
	std::cout << std::endl;
}

void Contact::display_perline()
{
	std::cout << "first name : " << this->fn << std::endl;
	std::cout << "last name : " << this->ln << std::endl;
	std::cout << "nickname : " << this->nn << std::endl;
	std::cout << "phone number : " << this->pn << std::endl;
	std::cout << "darkest secret : " << this->ds << std::endl;
}

void Contact::setdata(std::string fn, std::string ln, std::string nn,
					  std::string pn, std::string ds)
{
	this->fn = fn;
	this->ln = ln;
	this->nn = nn;
	this->pn = pn;
	this->ds = ds;
}
