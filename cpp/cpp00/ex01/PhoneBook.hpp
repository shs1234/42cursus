/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:02:25 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/19 15:11:53 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <limits>

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

void	putstrendl(std::string str);
void	putstr(std::string str);

#endif
