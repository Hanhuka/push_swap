/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:57:05 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/04 18:39:58 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"
#include <stdio.h>

void	move_stack_p(t_stk **stacka, t_stk **stackb, char *str)
{
	if (!ft_cp(str, "pa\n", 4) && stack_size(*stackb) > 0)
		push_o(stacka, stackb, 1);
	else if (!ft_cp(str, "pb\n", 4) && stack_size(*stacka) > 0)
		push_o(stacka, stackb, 2);
}

void	move_stack_s(t_stk **stacka, t_stk **stackb, char *str)
{
	if (!ft_cp(str, "sa\n", 4) && stack_size(*stacka) > 1)
		swap_o(stacka, stackb, 1);
	else if (!ft_cp(str, "sb\n", 4) && stack_size(*stackb) > 1)
		swap_o(stacka, stackb, 2);
	else if (!ft_cp(str, "ss\n", 4) && stack_size(*stacka) > 1
		&& stack_size(*stackb) > 1)
		swap_o(stacka, stackb, 3);
}

void	move_stack_r(t_stk **stacka, t_stk **stackb, char *str)
{
	if (!ft_cp(str, "ra\n", 4) && stack_size(*stacka) > 1)
		rotate_o(stacka, stackb, 1);
	else if (!ft_cp(str, "rb\n", 4) && stack_size(*stackb) > 1)
		rotate_o(stacka, stackb, 2);
	else if (!ft_cp(str, "rr\n", 4) && stack_size(*stacka) > 1
		&& stack_size(*stackb) > 1)
		rotate_o(stacka, stackb, 3);
}

void	move_stack_rr(t_stk **stacka, t_stk **stackb, char *str)
{
	if (!ft_cp(str, "rra\n", 5) && stack_size(*stacka) > 1)
		r_rotate_o(stacka, stackb, 1);
	else if (!ft_cp(str, "rrb\n", 5) && stack_size(*stackb) > 1)
		r_rotate_o(stacka, stackb, 2);
	else if (!ft_cp(str, "rrr\n", 5))
		r_rotate_o(stacka, stackb, 3);
}
