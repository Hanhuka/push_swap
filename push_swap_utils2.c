/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:40:49 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/11 17:45:56 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

int	*sort_array(int *array, int size)
{
	int	i;
	int	change;

	i = 0;
	while (i + 1 < size)
	{
		if (array[i] > array[i + 1])
		{
			change = array[i];
			array[i] = array[i + 1];
			array[i + 1] = change;
			i = 0;
		}
		else
			i++;
	}
	return (array);
}

int	find_pos(t_stk *stack, int value)
{
	int	i;

	i = 1;
	while (stack->value != value)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	*get_array(t_stk *stack)
{
	int	*chunks;
	int	size;
	int	i;

	size = stack_size(stack);
	i = 0;
	chunks = malloc(sizeof(int) * size);
	if (!chunks)
		return (0);
	while (i < size)
	{
		chunks[i] = stack->value;
		stack = stack->next;
		i++;
	}
	chunks = sort_array(chunks, size);
	return (chunks);
}

int	find_f_ocur(t_stk *stack, int min, int max)
{
	int	i;
	int	size;

	size = stack_size(stack);
	i = 1;
	while ((stack->value < min || stack->value > max) && i <= size)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	find_l_ocur(t_stk *stack, int min, int max)
{
	int	i;
	int	pos;
	int	size;

	i = 1;
	pos = 1;
	size = stack_size(stack);
	while (i < size + 1)
	{
		if (stack->value >= min && stack->value <= max)
			pos = i;
		stack = stack->next;
		i++;
	}
	return (pos);
}
