/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:46:16 by semin             #+#    #+#             */
/*   Updated: 2022/05/28 15:46:17 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	mainfunc(void)
{
	Zombie*	zombiehorde = zombieHorde(5, "zombie");
	for(int i = 0; i < 5; i++){
		zombiehorde[i].announce();
	}
	delete[] zombiehorde;
}

int	main(void)
{
	mainfunc();
	system("leaks Moar_brainz");
}
