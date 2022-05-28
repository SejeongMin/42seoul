/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:45:51 by semin             #+#    #+#             */
/*   Updated: 2022/05/28 15:45:53 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	mainfunc(void)
{
	Zombie	zombie1("stackZombie");
	zombie1.announce();

	Zombie	*zombie2 = newZombie("heapZombie");
	zombie2->announce();
	delete zombie2;

	randomChump("randomChumpZombie");
}

int	main(void)
{
	mainfunc();
	system("leaks BraiiiiiiinnnzzzZ");
}
