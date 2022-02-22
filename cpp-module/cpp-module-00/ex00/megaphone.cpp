/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:20:40 by semin             #+#    #+#             */
/*   Updated: 2022/02/23 04:20:40 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int	i = 1;
	int	j;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				std::cout << (char)(av[i][j] - 32);
			else
				std::cout << av[i][j];
			j++;
		}
		i++;
	}
	std::cout << "" << std::endl;
}
