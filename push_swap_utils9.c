/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils9.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:12:16 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/10 12:14:07 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	get_last(t_stk *stack)
{
	t_stk	*ptr;
	int		i;
	int		size;

	i = 0;
	ptr = stack;
	size = stack_size(stack);
	while (i < size - 1)
	{
		ptr = ptr->next;
		i++;
	}
	return (ptr->value);
}

int	get_biggest(t_stk *stack)
{
	t_stk	*ptr;
	int		i;
	int		val;
	int		size;

	i = 0;
	val = stack->value;
	ptr = stack;
	size = stack_size(stack);
	while (i < size)
	{
		if (ptr->value > val)
			val = ptr->value;
		ptr = ptr->next;
		i++;
	}
	return (val);
}

void	size_3(t_stk **stacka, t_stk **stackb)
{
	int	pos1;
	int	pos2;
	int	pos3;

	pos1 = (*stacka)->value;
	pos2 = (*stacka)->next->value;
	pos3 = (*stacka)->next->next->value;
	if (pos1 > pos2 && pos1 > pos3)
		rotate_o(stacka, stackb, 1);
	else if (pos2 > pos1 && pos2 > pos3)
		r_rotate_o(stacka, stackb, 1);
	if (!is_ordered(*stacka))
		swap_o(stacka, stackb, 1);
}

void	put_back(t_stk **stacka, t_stk **stackb, int opt)
{	
	if (opt == 1)
	{
		if (is_bigger(*stacka, (*stackb)->value)
			|| is_lower(*stacka, (*stackb)->value))
			put_order(stacka, stackb);
		else
			treat_middle(stacka, stackb, (*stackb)->value);
		push_o(stacka, stackb, 1);
	}
	else
		put_order(stacka, stackb);
}

void	treat_chunks2(t_stk **stacka, t_stk **stackb, int div)
{
	t_vs	var;
	int		size;

	size = stack_size(*stacka);
	var.size = size;
	var.ds = size / div;
	var.mid = (size / 2) + (size % 2);
	var.pos = var.mid - var.ds;
	var.pos2 = var.mid;
	var.array = get_array(*stacka);
	treat_else(stacka, stackb, var);
	free(var.array);
}
