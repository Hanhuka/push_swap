/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:20:41 by ralves-g          #+#    #+#             */
/*   Updated: 2022/06/20 15:36:03 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_f_ocur2(t_stk *stack, t_lm lm)
{
	int	i;
	int	size;

	size = stack_size(stack);
	i = 1;
	while ((stack->value < lm.min || stack->value > lm.max)
		&& (stack->value < lm.min2 || stack->value > lm.max2)
		&& i < size)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	find_l_ocur2(t_stk *stack, t_lm lm)
{
	int	i;
	int	pos;
	int	size;

	i = 1;
	pos = 1;
	size = stack_size(stack);
	while (i < size + 1)
	{
		if ((stack->value >= lm.min && stack->value <= lm.max)
			|| (stack->value >= lm.min2 && stack->value <= lm.max2))
			pos = i;
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	treat_odd(t_stk **stacka, t_stk **stackb, t_vs var)
{
	int		i;
	t_lm	lm;

	lm.min = var.array[var.pos];
	lm.max = var.array[var.pos + var.ds - 1];
	lm.min2 = var.array[var.pos];
	lm.max2 = var.array[var.pos + var.ds - 1];
	i = 0;
	while (i < var.ds)
	{
		least_moves(stacka, stackb,
			find_f_ocur(*stacka, var.array[var.pos],
				var.array[var.pos + var.ds - 1]),
			find_l_ocur(*stacka, var.array[var.pos],
				var.array[var.pos + var.ds - 1]));
		push_o(stacka, stackb, 2);
		i++;
	}
}

void	treat_side_chunks(t_stk **stacka, t_stk **stackb, t_vs var)
{
	int		i;
	int		min;
	int		max;
	t_lm	lm;

	lm.min = var.array[var.pos];
	lm.max = var.array[var.pos + var.ds - 1];
	lm.min2 = var.array[var.pos2];
	lm.max2 = var.array[var.pos2 + var.ds - 1];
	i = 0;
	while (i < (var.ds * 2))
	{
		min = find_f_ocur2(*stacka, lm);
		max = find_f_ocur2(*stacka, lm);
		least_moves(stacka, stackb, min, max);
		if (((*stacka)->value >= lm.min2 && (*stacka)->value <= lm.max2))
		{
			push_o(stacka, stackb, 2);
			rotate_o(stacka, stackb, 2);
		}
		else
			push_o(stacka, stackb, 2);
		i++;
	}
}

void	treat_else(t_stk **stacka, t_stk **stackb, t_vs var)
{
	int	i;

	i = 0;
	while (var.pos >= 0)
	{
		treat_side_chunks(stacka, stackb, var);
		var.pos -= var.ds;
		var.pos2 += var.ds;
	}
}

// void	treat_chunks2(t_stk **stacka, t_stk **stackb, int div)
// {
// 	t_vs	var;

// 	var.size = stack_size(*stacka);
// 	var.ds = stack_size(*stacka) / div;
// 	var.mid = (stack_size(*stacka) / 2) + (stack_size(*stacka) % 2);
// 	var.pos = var.mid - var.ds;
// 	var.pos2 = var.mid;
// 	var.array = get_array(*stacka);
// 	treat_else(stacka, stackb, var);
// }
