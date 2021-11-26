/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:49:23 by semin             #+#    #+#             */
/*   Updated: 2021/11/27 01:52:19 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_error(t_params *params)
{
    printf("Error\n");
    ft_free(&(params));
    exit(1);
}

int ft_atoi(char *s)
{
    long long   ret;

    ret = 0;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            exit(1);
        s++;
    }
    while (*s)
    {
        if (*s >= '0' && *s <= '9')
            ret = 10 * ret + (*s - '0');
        else
            exit(1);
        s++;
    }
    if (ret > 2147483647)
        exit(1);
    return (ret);
}
