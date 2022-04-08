/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:48:10 by semin             #+#    #+#             */
/*   Updated: 2022/04/09 02:48:11 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int	count;
public:
	PhoneBook();

	void	Add(int idx);
	void	Search();
	void	PrintHeader();
};

#endif
