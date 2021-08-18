/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvena <rvena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:41:49 by rvena             #+#    #+#             */
/*   Updated: 2021/07/16 19:05:28 by rvena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi2(const char *str, int *dig)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		*dig = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	res;
	int	dig;

	dig = 1;
	i = 0;
	res = 0;
	i = ft_atoi2(str, &dig);
	if (i > 0)
		return (-1);
	k = 0;
	while (str[i + k] != '\0')
	{
		if (k > 9)
			return (0);
		if (*(str + i + k) >= '0' && *(str + i + k) <= '9')
			res = (res * 10 + *(str + i + k) - 48);
		else
			return (0);
		k++;
	}
	return (dig * res);
}
