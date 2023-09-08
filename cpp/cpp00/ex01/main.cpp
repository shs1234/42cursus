/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:28:16 by hoseoson          #+#    #+#             */
/*   Updated: 2023/09/08 08:25:46 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;

	std::string cmd;
	while (1)
	{
		std::cout << "cmd : ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
		{
			if (pb.add())
				break;
		}
		else if (cmd == "SEARCH")
		{
			if (pb.search())
				break;
		}
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}
