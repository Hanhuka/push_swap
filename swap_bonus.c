/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:31 by ralves-g          #+#    #+#             */
/*   Updated: 2022/02/28 18:22:53 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	sw(t_stk **stack)
{
	t_stk	*ptr;

	if ((*stack)->next == NULL)
		return ;
	ptr = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	ptr->next = *stack;
	*stack = ptr;
}

void	swap_o(t_stk **stacka, t_stk**stackb, int opt)
{
	if (opt == 1)
	{
		sw(stacka);
	}
	else if (opt == 2)
	{
		sw(stackb);
	}
	else if (opt == 3)
	{
		sw(stacka);
		sw(stackb);
	}
	else
		return ;
}
