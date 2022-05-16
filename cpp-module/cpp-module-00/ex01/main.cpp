/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:48:13 by semin             #+#    #+#             */
/*   Updated: 2022/04/09 03:06:14 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string command;
	PhoneBook	phonebook;
	int	idx = 0;

	for(;;){
		std::cout << "Enter Command : ";
		std::cin >> command;
		
		if (!command.compare("ADD")){
			phonebook.Add(idx);
			idx++;
			if (idx == 8)
				idx = 0;
		}
		else if (!command.compare("SEARCH"))
			phonebook.Search();
		else if (!command.compare("EXIT"))
		{
			std::cout << "Program end" << std::endl;
			break;
		}
		else
			std::cout << "Wrong command" << std::endl;
	}
}
