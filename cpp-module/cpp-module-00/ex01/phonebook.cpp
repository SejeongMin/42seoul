/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:17:17 by semin             #+#    #+#             */
/*   Updated: 2022/06/29 14:48:53 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
}

void	PhoneBook::Add(int idx)
{
	this->contact[idx].setIndex(idx + 1);
	this->contact[idx].setField();
	if (this->count < 8)
		this->count++;
}

void	PhoneBook::PrintHeader()
{
	std::cout << std::setw(45) << std::setfill('-') << "\n";
	std::cout << "|";
	std::cout << "  Index  |" << std::setw(10);
	std::cout << " Firstname |" << std::setw(10);
	std::cout << " Lastname |" << std::setw(10);
	std::cout << " Nickname |" << std::setw(10) << std::endl;
	std::cout << std::setw(45) << std::setfill('-') << "\n";
	std::cout << std::setfill(' ');
}

void	PhoneBook::Search()
{
	PrintHeader();
	for (int i = 0; i < this->count; i++){
		this->contact[i].PrintContact();
		std::cout << std::setw(45) << std::setfill('-') << "\n";
		std::cout << std::setfill(' ');
	}

	int	idx;
	std::cout << "\nEnter the index of contact : ";
	std::cin >> idx;
	if (!std::cin)
	{
		std::cout << "Wrong index" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return ;
	}
	if (idx > count || idx <= 0)
		std::cout << "Contact doesn't exist." << std::endl;
	else
	{
		std::cout << "\n";
		this->contact[idx - 1].PrintFields();
		std::cout << std::endl;
	}
}
