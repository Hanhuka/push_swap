/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:24:48 by ralves-g          #+#    #+#             */
/*   Updated: 2022/06/21 12:30:33 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>
#include <stdio.h>

// void	print_stacks(t_stk *stacka, t_stk *stackb)
// {
// 	t_stk	*ptr;

// 	ptr = stacka;
// 	printf("_______________STACK_A_______________\n");
// 	if (!ptr)
// 		printf("\n\n                EMPTY\n");
// 	else
// 		printf("\n\n");
// 	while (ptr)
// 	{
// 		printf("                  %d\n", ptr->value);
// 		ptr = ptr->next;
// 	}
// 	printf("\n\n");
// 	ptr = stackb;
// 	printf("_______________STACK_B_______________\n");
// 	if (!ptr)
// 		printf("\n\n                EMPTY\n");
// 	else
// 		printf("\n\n");
// 	while (ptr)
// 	{
// 		printf("                  %d\n", ptr->value);
// 		ptr = ptr->next;
// 	}
// 	printf("\n_____________________________________\n");
// }

void	ft_lstclear(t_stk **stack)
{
	t_stk	*ptr;

	if (!stack || !*stack)
		return ;
	while (stack && *stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}

void	create_stack(t_stk **stacka, t_stk **stackb, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		while (args[i] && !args[i][0])
			i++;
		if (args[i])
			stackadd_back(stacka, new_module(ft_atoi(args[i])));
		i++;
	}
	stackb = NULL;
}

void	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			write(1, "ERROR\n", 6);
			exit(0);
		}
		i++;
	}
}

void	treat_input(t_stk **stacka, t_stk **stackb)
{
	char	*str;

	str = get_next_line(0);
	if (str)
	{
		treat_comm(str, stacka, stackb);
		check_spaces(str);
	}
	while (str != NULL)
	{
		str = get_next_line(0);
		if (str)
		{
			treat_comm(str, stacka, stackb);
			check_spaces(str);
			free(str);
		}
	}
}

int	main(int ac, char **av)
{
	t_stk	*stacka;
	t_stk	*stackb;
	char	**args;

	if (ac == 1)
		return (1);
	args = parse_everything(av);
	if (!checker(args))
	{
		write(1, "ERROR\n", 6);
		return (-1);
	}
	create_stack(&stacka, &stackb, args);
	delete_matrix(args);
	if (stack_size(stacka) == 0)
		return (0);
	treat_input(&stacka, &stackb);
	if (is_ordered(stacka) && stack_size(stackb) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stacka);
}
