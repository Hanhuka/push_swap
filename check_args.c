/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:51:53 by ralves-g          #+#    #+#             */
/*   Updated: 2022/06/20 15:13:54 by ralves-g         ###   ########.fr       */
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

int	repeats(char **args)
{
	int	i;
	int	i2;
	int	val;

	i = 0;
	while (args[i])
	{
		val = ft_atoi(args[i]);
		i2 = 0;
		while (args[i2])
		{
			if (ft_atoi(args[i2]) == val && i2 != i)
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

int	checker(char **args)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		if ((!is_number(args[i]) || !check_m_ex(args[i])))
			return (0);
		i++;
	}
	if (!repeats(args))
		return (0);
	return (1);
}
