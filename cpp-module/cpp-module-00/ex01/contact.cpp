/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:39:00 by semin             #+#    #+#             */
/*   Updated: 2022/05/23 22:39:04 by semin            ###   ########.fr       */
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
	
	std::cout << "Enter first name : ";
	std::cin >> this->field[0];
	std::cout << "Enter last name : ";
	std::cin >> this->field[1];
	std::cout << "Enter nickname : ";
	std::cin >> this->field[2];
	std::cout << "Enter phone number : ";
	std::cin >> this->field[3];
	std::cout << "Enter darkest secret : ";
	std::cin >> this->field[4];
}

void	Contact::PrintField(std::string value)
{
	std::string	str (value);

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
