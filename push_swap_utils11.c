/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils11.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:26:47 by ralves-g          #+#    #+#             */
/*   Updated: 2022/10/20 15:08:33 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

// static	void	parse(int i, char **join, char ***av)
// {
// 	char	*space;
// 	char	*cpy;

// 	cpy = ft_strdup(*join);
// 	if (*join)
// 		free(*join);
// 	space = ft_strdup(" ");
// 	*join = ft_strjoin2(cpy, space);
// 	free(space);
// 	if (cpy)
// 		free(cpy);
// 	cpy = ft_strdup(*join);
// 	if (*join)
// 		free(*join);
// 	*join = ft_strjoin2(cpy, (*av)[i]);
// }

static	char	*parse(int i, char *join, char **av)
{
	char	*space;
	char	*cpy;
	char	*joined;

	cpy = ft_strdup(join);
	space = ft_strdup(" ");
	if (join)
		free(join);
	join = ft_strjoin2(cpy, space);
	free(space);
	if (cpy)
		free(cpy);
	cpy = ft_strdup(join);
	if (join)
		free(join);
	joined = ft_strjoin2(cpy, av[i]);
	if (cpy)
		free(cpy);
	return (joined);
}

// char	**parse_everything(char **av)
// {
// 	int		i;
// 	char	*join;
// 	char	**parsed;

// 	i = 1;
// 	while (av[i])
// 	{
// 		parse(i, &join, &av);
// 		i++;
// 	}
// 	parsed = ft_split(join, ' ');
// 	free(join);
// 	return (parsed);
// }

char	**parse_everything(char **av)
{
	int		i;
	char	*join;
	char	**parsed;

	join = NULL;
	i = 1;
	while (av[i])
	{
		join = parse(i, join, av);
		i++;
	}
	parsed = ft_split(join, ' ');
	free(join);
	return (parsed);
}

void	delete_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
