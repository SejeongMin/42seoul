/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:46:53 by semin             #+#    #+#             */
/*   Updated: 2022/05/28 15:46:54 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
	std::string _name;

public:
	void	announce(void);
	void	naming(std::string name);
	Zombie();
	Zombie(std::string name);
	~Zombie(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
