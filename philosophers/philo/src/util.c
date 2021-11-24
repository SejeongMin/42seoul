/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:49:23 by semin             #+#    #+#             */
/*   Updated: 2021/11/24 18:22:49 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_error()
{
    //malloc free
    exit(1);
}

int ft_atoi(char *s)
{
    long long   ret;

    ret = 0;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            ft_error();
        s++;
    }
    while (*s)
    {
        if (*s >= '0' && *s <= '9')
            ret = 10 * ret + (*s - '0');
        else
            ft_error();
        s++;
    }
    if (ret > 2147483647)
        ft_error();
    return (ret);
}
