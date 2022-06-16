/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:51:53 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/07 12:06:00 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_m_ex(char *str)
{
	if ((str[0] == '-' || str[0] == '+')
		&& (str[1] < '0' || str[1] > '9' || !str[1]))
		return (0);
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}

int	repeats(int ac, char **av)
{
	int	i;
	int	i2;
	int	val;

	i = 1;
	while (i < ac)
	{
		val = ft_atoi(av[i]);
		i2 = 1;
		while (i2 < ac)
		{
			if (ft_atoi(av[i2]) == val && i2 != i)
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

int	checker(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac <= i)
		return (0);
	while (i < ac)
	{
		if ((!is_number(av[i]) || !check_m_ex(av[i])))
			return (0);
		i++;
	}
	if (!repeats(ac, av))
		return (0);
	return (1);
}
