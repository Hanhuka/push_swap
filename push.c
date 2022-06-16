/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:32 by ralves-g          #+#    #+#             */
/*   Updated: 2022/02/10 05:05:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

void	push(t_stk **stack1, t_stk **stack2)
{
	t_stk	*ptr;

	if (!(*stack1))
		return ;
	ptr = *stack1;
	*stack1 = ((*stack1)->next);
	ptr->next = *stack2;
	*stack2 = ptr;
}

void	push_o(t_stk **stacka, t_stk **stackb, int opt)
{
	if (opt == 1)
	{
		write(1, "pa\n", 3);
		push(stackb, stacka);
	}
	else if (opt == 2)
	{
		write(1, "pb\n", 3);
		push(stacka, stackb);
	}
	else
		return ;
}
