/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:38:56 by semin             #+#    #+#             */
/*   Updated: 2022/05/23 22:38:58 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <iostream>

class Contact
{
private:
	int	index;
	std::string	field[5];
public:
	Contact();

	void	setIndex(int idx);
	void	setField();
	void	PrintField(std::string value);
	void	PrintFields();
	void	PrintContact();
};

#endif
