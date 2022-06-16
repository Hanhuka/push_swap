/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 03:55:55 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/10 12:11:39 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_lower(t_stk *stack, int value)
{
	int		low;
	int		i;
	t_stk	*ptr;
	int		size;

	ptr = 0;
	low = 0;
	i = 0;
	ptr = stack;
	size = stack_size(stack);
	while (i < size && ptr->value > value)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == size)
		low = 1;
	return (low);
}

int	is_bigger(t_stk *stack, int value)
{
	int		big;
	int		i;
	t_stk	*ptr;
	int		size;

	ptr = 0;
	big = 0;
	i = 0;
	ptr = stack;
	size = stack_size(stack);
	while (i < size && ptr->value < value)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == size)
		big = 1;
	return (big);
}

int	find_smallest(t_stk *stack)
{
	int		pos;
	int		val;
	int		i;
	t_stk	*ptr;
	int		size;

	size = stack_size(stack);
	val = stack->value;
	pos = 1;
	i = 1;
	ptr = stack;
	while (i <= size)
	{
		if (ptr->value < val)
		{
			val = ptr->value;
			pos = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (pos);
}

int	get_smallest(t_stk *stack)
{
	int		pos;
	int		val;
	int		i;
	int		size;
	t_stk	*ptr;

	size = stack_size(stack);
	val = stack->value;
	pos = 1;
	i = 1;
	ptr = stack;
	while (i <= size)
	{
		if (ptr->value < val)
		{
			val = ptr->value;
			pos = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (val);
}

void	put_order(t_stk **stacka, t_stk **stackb)
{
	int	moves;
	int	opt;
	int	size;

	size = stack_size(*stacka);
	opt = 0;
	if (find_smallest(*stacka)
		> size / 2 + size % 2)
	{
		moves = size - find_smallest(*stacka) + 1;
		opt = 1;
	}
	else
		moves = find_smallest(*stacka) - 1;
	move(stacka, stackb, moves, opt);
}
