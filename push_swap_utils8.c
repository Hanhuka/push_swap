/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:09:43 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/10 12:37:35 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_bfr(t_stk *stack, int value)
{
	t_stk	*ptr;

	ptr = stack;
	if (value == ptr->value)
	{
		return (get_last(stack));
	}
	while (ptr->next->value != value)
		ptr = ptr->next;
	return (ptr->value);
}

int	moves_l_a(t_stk *stack)
{
	t_stk	*ptr;
	int		i;

	ptr = stack;
	i = 0;
	while (ptr->value != get_smallest(stack))
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

t_ms	calc_opt_a(t_stk *stack, int i)
{
	t_ms	m;
	int		size;

	size = stack_size(stack);
	if (i >= (size / 2 + size % 2))
	{
		m.moves = size - i;
		m.opt = 1;
	}
	else
	{
		m.moves = i;
		m.opt = 0;
	}
	return (m);
}

t_ms	calc_moves_a(t_stk *stack, int value)
{
	t_ms	m;
	t_stk	*ptr;
	int		i;

	ptr = stack;
	i = 0;
	if (value < ptr->value && (value > get_last(stack)
			|| get_last(stack) == get_biggest(stack)))
	{
		m.moves = 0;
		return (m);
	}
	while (!(value < ptr->value && value > get_bfr(stack, ptr->value))
		&& i < stack_size(stack) - 1)
	{
		ptr = ptr->next;
		i++;
	}
	if (is_lower(stack, value))
	{
		i = moves_l_a(stack);
	}
	m = calc_opt_a(stack, i);
	return (m);
}

t_ms	calc_moves_b(t_stk *stack, int value)
{
	t_ms	m;
	t_stk	*ptr;
	int		i;
	int		size;

	size = stack_size(stack);
	ptr = stack;
	i = 1;
	while (ptr->value != value)
	{
		ptr = ptr->next;
		i++;
	}
	if (i >= (size / 2 + size % 2))
	{
		m.moves = size - i + 1;
		m.opt = 1;
	}
	else
	{
		m.moves = i - 1;
		m.opt = 0;
	}
	return (m);
}
