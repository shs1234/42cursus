/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:28:16 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/17 13:35:56 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;

	std::string command;
	while (1)
	{
		std::cout << "command : ";
		std::getline(std::cin, command);
		if (command == "ADD")
			pb.add();
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
			break ;
		else
			pb.invalidcommand();
		// command.clear();
	}
	return (0);
}
