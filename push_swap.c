/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:31 by ralves-g          #+#    #+#             */
/*   Updated: 2022/10/17 18:01:03 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

// void print_a(t_stk *stacka)
// {
// 		t_stk	*ptr;

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

// int	main(int ac, char **av)
// {
// 	t_stk	*stacka;
// 	t_stk	*stackb;
// 	int		i;

// 	stacka = NULL;
// 	i = 1;
// 	if (ac == 1)
// 		return (0);
// 	if (!checker(ac, av))
// 	{
// 		write(1, "ERROR\n", 6);
// 		return (-1);
// 	}
// 	while (i < ac)
// 	{
// 		while (i < ac && !av[i][0])
// 			i++;
// 		if (i < ac)
// 			stackadd_back(&stacka, new_module(ft_atoi(av[i])));
// 		i++;
// 	}
// 	stackb = NULL
// 	if (stacka)
// 		sorter(&stacka, &stackb);
// 	ft_lstclear(&stacka);
// }

void	create_stack(t_stk **stacka, char **args)
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
}

int	main(int ac, char **av)
{
	t_stk	*stacka;
	t_stk	*stackb;
	char	**args;

	stacka = NULL;
	if (ac == 1)
		return (0);
	args = parse_everything(av);
	if (!checker(args))
	{
		write(1, "ERROR\n", 6);
		return (-1);
	}
	create_stack(&stacka, args);
	delete_matrix(args);
	stackb = NULL;
	if (stacka)
		sorter(&stacka, &stackb);
	ft_lstclear(&stacka);
}
