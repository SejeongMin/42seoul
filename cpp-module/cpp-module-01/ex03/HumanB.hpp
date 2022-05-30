/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:11:15 by semin             #+#    #+#             */
/*   Updated: 2022/05/30 18:11:16 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
private:
	Weapon		*_weapon;
	std::string	_name;

public:
	HumanB();
	HumanB(std::string name);
	~HumanB();

	void		setWeapon(Weapon &weapon);
	void		attack();
};

#endif
