/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 03:48:36 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/11 17:44:59 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

typedef struct pb
{
	int	moves;
	int	moves2;
	int	moves3;
	int	value;
	int	value2;
	int	value3;
	int	opt;
	int	opt2;
	int	opt3;
}	t_pb;

void	least_moves(t_stk **stacka, t_stk **stackb, int pos1, int pos2)
{
	int	size;

	size = stack_size(*stacka);
	if (pos1 <= size / 2 + size % 2)
		move(stacka, stackb, pos1 - 1, 0);
	else
		move(stacka, stackb, size - pos2 + 1, 1);
}

void	treat_chunk(t_stk **stacka, t_stk **stackb, int div_size)
{
	int		pos;
	int		i;
	int		*array;
	t_stk	*ptr;
	int		size;

	ptr = *stacka;
	pos = 0;
	array = get_array(*stacka);
	size = stack_size(*stacka);
	while (size > div_size)
	{
		i = 0;
		while (i < div_size && size > 3)
		{
			least_moves(stacka, stackb,
				find_f_ocur(*stacka, array[pos], array[pos + div_size - 1]),
				find_l_ocur(*stacka, array[pos], array[pos + div_size - 1]));
			push_o(stacka, stackb, 2);
			i++;
		}
		pos += div_size;
	}
	free(array);
}

void	move(t_stk **stacka, t_stk **stackb, int moves, int opt)
{
	while (moves > 0 && opt == 1)
	{
		r_rotate_o(stacka, stackb, 1);
		moves--;
	}
	while (moves > 0 && opt == 0)
	{
		rotate_o(stacka, stackb, 1);
		moves--;
	}
}

void	treat_middle(t_stk **stack, t_stk **stack2, int value)
{	
	int	moves;
	int	opt;
	int	size;

	opt = 0;
	moves = 0;
	size = stack_size(*stack);
	if (find_middle(*stack, value) > size / 2)
	{
		moves = size - find_middle(*stack, value);
		opt = 1;
	}
	else
		moves = find_middle(*stack, value);
	move(stack, stack2, moves, opt);
}

int	find_middle(t_stk *stack, int value)
{
	int		i;
	int		pos;
	int		val;
	t_stk	*ptr;
	int		size;

	i = 1;
	pos = i;
	ptr = stack;
	size = stack_size(stack);
	val = get_smallest(stack);
	while (i <= size)
	{
		if (ptr->value < value && ptr->value >= val)
		{
			val = ptr->value;
			pos = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (pos);
}
