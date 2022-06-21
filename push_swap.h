/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:58 by ralves-g          #+#    #+#             */
/*   Updated: 2022/06/21 15:51:59 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//# define malloc(x) NULL

typedef struct stack
{
	int				value;
	struct stack	*next;
}	t_stk;

typedef struct ms
{
	int	moves;
	int	opt;
}	t_ms;

typedef struct s_vars
{
	int	size;
	int	*array;
	int	mid;
	int	pos;
	int	pos2;
	int	ds;
}	t_vs;

typedef struct s_limits
{
	int	min;
	int	max;
	int	min2;
	int	max2;
}	t_lm;

//push_swap_utils
int			stack_size(t_stk *stack);
long int	ft_atoi(const char *str);
t_stk		*new_module(int value);
void		stackadd_back(t_stk **stack, t_stk *new);
int			is_ordered(t_stk *stacka);

//funtions
void		swap_o(t_stk **stacka, t_stk**stackb, int opt);
void		push_o(t_stk **stacka, t_stk**stackb, int opt);
void		rotate(t_stk **stack);
void		rotate_o(t_stk **stacka, t_stk **stackb, int opt);
void		r_rotate(t_stk **stack);
void		r_rotate_o(t_stk **stacka, t_stk **stackb, int opt);

//push_swap
void		print_stacks(t_stk *stacka, t_stk *stackb);
void		print_a(t_stk *stacka);
void		ft_lstclear(t_stk **stack);

//check_args
int			is_number(char *str);
int			repeats(char **args);
int			beyond_extremes(int ac, char **av);
int			checker(char **args);
int			only_space(char *str);

//sorter
void		size_3(t_stk **stacka, t_stk **stackb);
void		put_back(t_stk **stacka, t_stk **stackb, int opt);
void		sorter(t_stk **stacka, t_stk **stackb);
void		sort_100(t_stk **stacka, t_stk **stackb);
void		sort_500(t_stk **stacka, t_stk **stackb);

//push_swap_utils2
int			*sort_array(int *array, int size);
int			*get_array(t_stk *stack);
void		treat_chunk(t_stk **stacka, t_stk **stackb, int div_size);
int			find_f_ocur(t_stk *stack, int min, int max);
int			find_l_ocur(t_stk *stack, int min, int max);

//push_swap_utils3
void		least_moves(t_stk **stacka, t_stk **stackb, int pos1, int pos2);
void		treat_chunk(t_stk **stacka, t_stk **stackb, int div_size);
void		treat_middle(t_stk **stack, t_stk **stack2, int value);
void		move(t_stk **stacka, t_stk **stackb, int moves, int opt);
int			find_middle(t_stk *stack, int value);

//push_swap_utils4
int			is_lower(t_stk *stack, int value);
int			is_bigger(t_stk *stack, int value);
int			find_smallest(t_stk *stack);
int			get_smallest(t_stk *stack);
void		put_order(t_stk **stacka, t_stk **stackb);

//push_swap_utils5 ---------> A to B
int			find_f_ocur2(t_stk *stack, t_lm lm);
int			find_l_ocur2(t_stk *stack, t_lm lm);
void		treat_odd(t_stk **stacka, t_stk **stackb, t_vs var);
void		treat_side_chunks(t_stk **stacka, t_stk **stackb, t_vs var);
void		treat_else(t_stk **stacka, t_stk **stackb, t_vs var);
void		treat_chunks2(t_stk **stacka, t_stk **stackb, int div);

//push_swap_utils6
int			find_biggest(t_stk *stack);
int			find_second(t_stk *stack);
int			find_third(t_stk *stack);

//push_swap_utils7
void		move_opt1(t_stk **stacka, t_stk **stackb, t_ms best, t_ms best2);
void		move_opt0(t_stk **stacka, t_stk **stackb, t_ms best, t_ms best2);
void		move_dif(t_stk **stacka, t_stk **stackb, t_ms best, int stk);
void		push_best(t_stk **stacka, t_stk **stackb, t_ms best, t_ms best2);
void		treat_plus(t_stk **stacka, t_stk **stackb);

//push_swap_utils8
int			get_bfr(t_stk *stack, int value);
int			moves_l_a(t_stk *stack);
t_ms		calc_opt_a(t_stk *stack, int i);
t_ms		calc_moves_a(t_stk *stack, int value);
t_ms		calc_moves_b(t_stk *stack, int value);

//push_swap_utils9
int			get_last(t_stk *stack);
int			get_biggest(t_stk *stack);
void		size_3(t_stk **stacka, t_stk **stackb);
void		put_back(t_stk **stacka, t_stk **stackb, int opt);
void		order_stack(t_stk **stacka, t_stk **stackb);

//push_swap_utils10
char		*ft_strjoin2(char const *s1, char const *s2);
char		**ft_split(char const *str, char c);

//push_swap_utils11
char		*ft_strdup(const char *s1);
int			ft_strlen2(const char *str);
char		**parse_everything(char **av);
void		delete_matrix(char **matrix);

//push_swap_utils_test
int			*make_array(t_stk *stack);
int			*convrt_array(int *indexer, int size);

#endif
