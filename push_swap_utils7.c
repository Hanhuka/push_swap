/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:12:01 by ralves-g          #+#    #+#             */
/*   Updated: 2022/06/02 13:18:19 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// typedef struct ms
// {
// 	int	moves;
// 	int	opt;
// }	t_ms;

// int	get_bfr(t_stk *stack, int value)
// {
// 	t_stk	*ptr;

// 	ptr = stack;
// 	if (value == ptr->value)
// 	{
// 		return (get_last(stack));
// 	}
// 	while (ptr->next->value != value)
// 		ptr = ptr->next;
// 	return (ptr->value);
// }

// int	moves_l_a(t_stk *stack)
// {
// 	t_stk	*ptr;
// 	int		i;

// 	ptr = stack;
// 	i = 0;
// 	while (ptr->value != get_smallest(stack))
// 	{
// 		ptr = ptr->next;
// 		i++;
// 	}
// 	return (i);
// }

// t_ms	calc_opt_a(t_stk *stack, int i)
// {
// 	t_ms	m;

// 	if (i >= (stack_size(stack) / 2 + stack_size(stack) % 2))
// 	{
// 		m.moves = stack_size(stack) - i;
// 		m.opt = 1;
// 	}
// 	else
// 	{
// 		m.moves = i;
// 		m.opt = 0;
// 	}
// 	return (m);
// }

// t_ms	calc_moves_a(t_stk *stack, int value)
// {
// 	t_ms	m;
// 	t_stk	*ptr;
// 	int		i;

// 	ptr = stack;
// 	i = 0;
// 	if (value < ptr->value && (value > get_last(stack)
// 		|| get_last(stack) == get_biggest(stack)))
// 	{
// 		m.moves = 0;
// 		return (m);
// 	}
// 	while (!(value < ptr->value && value > get_bfr(stack, ptr->value))
// 		&& i < stack_size(stack) - 1)
// 	{
// 		ptr = ptr->next;
// 		i++;
// 	}
// 	if (is_lower(stack, value))
// 	{
// 		i = moves_l_a(stack);
// 	}
// 	m = calc_opt_a(stack, i);
// 	return (m);
// }

// t_ms	calc_moves_b(t_stk *stack, int value)
// {
// 	t_ms	m;
// 	t_stk	*ptr;
// 	int		i;

// 	ptr = stack;
// 	i = 1;
// 	while (ptr->value != value)
// 	{
// 		ptr = ptr->next;
// 		i++;
// 	}
// 	if (i >= (stack_size(stack) / 2 + stack_size(stack) % 2))
// 	{
// 		m.moves = stack_size(stack) - i + 1;
// 		m.opt = 1;
// 	}
// 	else
// 	{
// 		m.moves = i - 1;
// 		m.opt = 0;
// 	}
// 	return (m);
// }

void	move_opt1(t_stk **stacka, t_stk **stackb, t_ms best, t_ms best2)
{
	while (best.moves > 0 && best2.moves > 0)
	{
		r_rotate_o(stacka, stackb, 3);
		best.moves--;
		best2.moves--;
	}
	while (best.moves > 0)
	{
		r_rotate_o(stacka, stackb, 1);
		best.moves--;
	}
	while (best2.moves > 0)
	{
		r_rotate_o(stacka, stackb, 2);
		best2.moves--;
	}
}

void	move_opt0(t_stk **stacka, t_stk **stackb, t_ms best, t_ms best2)
{
	while (best.moves > 0 && best2.moves > 0)
	{
		rotate_o(stacka, stackb, 3);
		best.moves--;
		best2.moves--;
	}
	while (best.moves > 0)
	{
		rotate_o(stacka, stackb, 1);
		best.moves--;
	}
	while (best2.moves > 0)
	{
		rotate_o(stacka, stackb, 2);
		best2.moves--;
	}
}

void	move_dif(t_stk **stacka, t_stk **stackb, t_ms best, int stk)
{
	while (best.moves > 0 && best.opt == 1)
	{
		r_rotate_o(stacka, stackb, stk);
		best.moves--;
	}
	while (best.moves > 0 && best.opt == 0)
	{
		rotate_o(stacka, stackb, stk);
		best.moves--;
	}
}

void	push_best(t_stk **stacka, t_stk **stackb, t_ms best, t_ms best2)
{
	if (best.opt == 1 && best2.opt == 1)
		move_opt1(stacka, stackb, best, best2);
	else if (best.opt == 0 && best2.opt == 0)
		move_opt0(stacka, stackb, best, best2);
	else
	{
		move_dif(stacka, stackb, best, 1);
		move_dif(stacka, stackb, best2, 2);
	}
	push_o(stacka, stackb, 1);
}

void	treat_plus(t_stk **stacka, t_stk **stackb)
{
	t_stk	*ptr;
	t_ms	best;
	t_ms	best2;
	t_ms	test;
	t_ms	test2;

	ptr = *stackb;
	best = calc_moves_a(*stacka, ptr->value);
	best2 = calc_moves_b(*stackb, ptr->value);
	while (ptr)
	{
		test = calc_moves_a(*stacka, ptr->value);
		test2 = calc_moves_b(*stackb, ptr->value);
		if (best.moves + best2.moves > test.moves + test2.moves)
		{
			best = test;
			best2 = test2;
		}
		ptr = ptr->next;
	}
	push_best(stacka, stackb, best, best2);
}
