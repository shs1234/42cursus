/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:02:25 by hoseoson          #+#    #+#             */
/*   Updated: 2023/09/14 12:45:07 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>

class PhoneBook
{
private:
	int index;
	int count;
	Contact contact[8];

public:
	PhoneBook();
	void add();
	void search();
};

#endif
