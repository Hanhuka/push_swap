/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:31:21 by ralves-g          #+#    #+#             */
/*   Updated: 2022/02/28 18:54:04 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <fcntl.h>

typedef struct stack
{
	int				value;
	struct stack	*next;
}	t_stk;

//get_next_line
char		*get_next_line(int fd);
size_t		ft_strlen(const char *word);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *b, int c, size_t len);
char		*cpyfrm2(char *str, int i, int end);

//push_swap_utils
int			stack_size(t_stk *stack);
long int	ft_atoi(const char *str);
t_stk		*new_module(int value);
void		stackadd_back(t_stk **stack, t_stk *new);
int			is_ordered(t_stk *stacka);

//check_args
int			is_number(char *str);
int			repeats(int ac, char **av);
int			beyond_extremes(int ac, char **av);
int			checker(int ac, char **av);

//checker_utils
void		treat_comm(char *str, t_stk **stacka, t_stk **stackb);
int			ft_cp(const char *s1, const char *s2, size_t n);
int			comp(char *str, char *test);

//move_stack

void		move_stack_s(t_stk **stacka, t_stk **stackb, char *str);
void		move_stack_p(t_stk **stacka, t_stk **stackb, char *str);
void		move_stack_r(t_stk **stacka, t_stk **stackb, char *str);
void		move_stack_rr(t_stk **stacka, t_stk **stackb, char *str);

//moves
void		swap_o(t_stk **stacka, t_stk**stackb, int opt);
void		push_o(t_stk **stacka, t_stk**stackb, int opt);
void		rotate(t_stk **stack);
void		rotate_o(t_stk **stacka, t_stk **stackb, int opt);
void		r_rotate(t_stk **stack);
void		r_rotate_o(t_stk **stacka, t_stk **stackb, int opt);

#endif