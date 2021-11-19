/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/11/19 19:34:02 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(void)
{
	t_time	start, end;
	gettimeofday(&start, 0);
	sleep(1);
	gettimeofday(&end, 0);
	printf("%f s\n", end.tv_sec - start.tv_sec);
}
