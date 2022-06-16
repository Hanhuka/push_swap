/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:34:31 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/02 10:44:43 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>
#include <stdio.h>

int	ft_cp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1 && *(s1 + i) == *(s2 + i)
		&& *(s1 + i) != '\0' && *(s2 + i) != '\0')
		i++;
	return ((*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)));
}

void	treat_comm(char *str, t_stk **stacka, t_stk **stackb)
{
	if (!ft_cp(str, "pa\n", 4) || !ft_cp(str, "pb\n", 4))
		move_stack_p(stacka, stackb, str);
	else if (!ft_cp(str, "sa\n", 4) || !ft_cp(str, "sb\n", 4)
		|| !ft_cp(str, "ss\n", 4))
		move_stack_s(stacka, stackb, str);
	else if (!ft_cp(str, "ra\n", 4) || !ft_cp(str, "rb\n", 4)
		|| !ft_cp(str, "rr\n", 4))
		move_stack_r(stacka, stackb, str);
	else if (!ft_cp(str, "rra\n", 5) || !ft_cp(str, "rrb\n", 5)
		|| !ft_cp(str, "rrr\n", 5))
		move_stack_rr(stacka, stackb, str);
	else
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
}
