/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:11:26 by semin             #+#    #+#             */
/*   Updated: 2022/07/23 18:20:30 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << this->type << " destructed" << std::endl;
}

const std::string	&Weapon::getType()
{
	const std::string	&weaponREF = this->type;
	return weaponREF;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
