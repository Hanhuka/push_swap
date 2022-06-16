/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:32 by ralves-g          #+#    #+#             */
/*   Updated: 2022/02/28 18:22:32 by ralves-g         ###   ########.fr       */
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
		push(stackb, stacka);
	}
	else if (opt == 2)
	{
		push(stacka, stackb);
	}
	else
		return ;
}
