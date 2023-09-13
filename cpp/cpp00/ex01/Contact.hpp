/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:38:31 by hoseoson          #+#    #+#             */
/*   Updated: 2023/09/13 19:41:05 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;

public:
	void setdata(std::string fn, std::string ln, std::string nn, std::string pn,
				 std::string ds);
	void display(int i);
	void display_perline();
};

#endif
