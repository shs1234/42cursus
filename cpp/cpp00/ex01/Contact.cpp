/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:38:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/19 15:40:06 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::display()
{
	std::cout << this->fn << " ";
	std::cout << this->ln << " ";
	std::cout << this->nn << " ";
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
