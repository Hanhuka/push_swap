/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:59:32 by ralves-g          #+#    #+#             */
/*   Updated: 2022/06/21 12:28:03 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*joiner(char const *s1, char const *s2, int size1, int size2)
{
	int		i;
	int		i2;
	char	*ptr;

	i = 0;
	ptr = malloc(size1 + size2 + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2])
	{
		ptr[i + i2] = s2[i2];
		i2++;
	}
	ptr[i + i2] = '\0';
	return (ptr);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		size1;
	int		size2;

	if (!s1 && s2)
		return ((char *)s2);
	if (s1 && !s2)
		return ((char *)s1);
	size1 = ft_strlen2(s1);
	size2 = ft_strlen2(s2);
	return (joiner(s1, s2, size1, size2));
}

static int	num_splits(char const *str, char c)
{
	int	i;
	int	splits;

	splits = 1;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			splits++;
		i++;
	}
	return (splits);
}

static char	*ft_substr(char const *str, int start, int end)
{
	char	*sub;
	int		i;

	i = 0;
	if (start > end)
		return (NULL);
	sub = malloc(end - start + 1);
	while (start <= end)
	{
		sub[i] = str[start];
		start++;
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		i;
	int		start;
	int		i2;

	i = 0;
	i2 = 0;
	split = malloc(sizeof(char *) * num_splits(str, c));
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && (!str[i + 1] || str[i + 1] == c))
		{
			start = i;
			while (!(str[start] != c && (!str[start - 1]
						|| str[start - 1] == c)))
				start--;
			split[i2++] = ft_substr(str, start, i);
		}
		i++;
	}
	split[i2] = NULL;
	return (split);
}
