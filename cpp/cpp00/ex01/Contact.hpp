/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:38:31 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/18 19:23:42 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

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
	void display();
};

#endif
