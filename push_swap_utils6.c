/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:19:57 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/10 12:35:57 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_biggest(t_stk *stack)
{
	int		val;
	int		i;
	t_stk	*ptr;
	int		size;

	size = stack_size(stack);
	val = stack->value;
	i = 0;
	ptr = stack;
	while (i < size)
	{
		if (ptr->value > val)
			val = ptr->value;
		ptr = ptr->next;
		i++;
	}
	return (val);
}

int	find_second(t_stk *stack)
{
	int		val;
	int		i;
	t_stk	*ptr;
	int		size;

	size = stack_size(stack);
	if (stack->value == find_biggest(stack))
		val = stack->next->value;
	else
		val = stack->value;
	i = 0;
	ptr = stack;
	while (i < size)
	{
		if (ptr->value > val && ptr->value != find_biggest(stack))
			val = ptr->value;
		ptr = ptr->next;
		i++;
	}
	return (val);
}

int	find_third(t_stk *stack)
{
	int		val;
	int		i;
	t_stk	*ptr;
	int		size;

	size = stack_size(stack);
	if (stack->value != find_biggest(stack)
		&& stack->value != find_second(stack))
		val = stack->value;
	else if (stack->next->value != find_biggest(stack)
		&& stack->next->value != find_second(stack))
		val = stack->next->value;
	else
		val = stack->next->next->value;
	i = 0;
	ptr = stack;
	while (i < size)
	{
		if (ptr->value > val && ptr->value != find_biggest(stack)
			&& ptr->value != find_second(stack))
			val = ptr->value;
		ptr = ptr->next;
		i++;
	}
	return (val);
}
