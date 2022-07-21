/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:39:00 by semin             #+#    #+#             */
/*   Updated: 2022/07/21 22:01:58 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string field_name[5] = {
	"first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

Contact::Contact()
{
	this->index = -1;
	this->field[0] = std::string ();
	this->field[1] = std::string ();
	this->field[2] = std::string ();
	this->field[3] = std::string ();
}

void	Contact::setIndex(int idx)
{
	this->index = idx;
}

void	Contact::setField()
{
	for (int i = 0; i < 5; i++){
		std::cout << "Enter " << field_name[i] << " : ";
		std::cin >> this->field[i];
		if (std::cin.eof())
			return;
	}
}

void	Contact::PrintField(std::string value)
{
	std::string	str(value);

	if (value.length() > 10)
	{
		str.resize(10);
		str.replace(9, 1, ".");
	}
	std::cout << std::setw(10) << str << "|";
}

void	Contact::PrintContact()
{
	std::cout << "|" << std::setw(10) << this->index << "|";
	for (int i = 0; i < 3; i++){
		PrintField(this->field[i]);
	}
	std::cout << std::endl;
}

void	Contact::PrintFields()
{
	for (int i = 0; i < 5; i++){
		std::cout << field_name[i] << " : ";
		std::cout << this->field[i] << std::endl;
	}
}
