/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:16:32 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/11 11:04:48 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	num;
	long int	neg;

	num = 0;
	neg = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	if (str[i] == '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && neg != 0)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * neg);
}

t_stk	*new_module(int value)
{		
	t_stk	*linker;

	linker = (t_stk *)malloc(sizeof(*linker));
	if (linker == NULL)
		return (0);
	linker->value = value;
	linker->next = NULL;
	return (linker);
}

void	stackadd_back(t_stk **stack, t_stk *new)
{
	t_stk	*ptr;

	ptr = *stack;
	if (!new)
	{
		ft_lstclear(stack);
		write(1, "ERROR: malloc = NULL\n", 21);
		exit(1);
	}
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	if (ptr == NULL)
		ptr = new;
	while (ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new;
}

int	stack_size(t_stk *stack)
{
	t_stk	*ptr;
	int		i;

	i = 0;
	ptr = stack;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	is_ordered(t_stk *stack)
{
	t_stk	*ptr;
	int		i;
	int		size;

	size = stack_size(stack);
	ptr = stack;
	i = 1;
	while (i < size && ptr->value < ptr->next->value)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == size)
		return (1);
	else
		return (0);
}
