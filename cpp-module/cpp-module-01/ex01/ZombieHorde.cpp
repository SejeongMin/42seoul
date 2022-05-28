/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:46:55 by semin             #+#    #+#             */
/*   Updated: 2022/05/28 15:46:56 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	zombiehorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombiehorde[i].naming(name + std::to_string(i));
	return zombiehorde;
}
