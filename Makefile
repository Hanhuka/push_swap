# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by ralves-g          #+#    #+#              #
#    Updated: 2022/10/17 18:03:40 by ralves-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g
RM			= rm -f

NAME		= push_swap

NAME_B		= checker

INCLUDE		= push_swap.h
SRCS		= push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c \
			push_swap_utils4.c push_swap_utils5.c push_swap_utils6.c \
			push_swap_utils7.c push_swap_utils8.c push_swap_utils9.c \
			push_swap_utils10.c push_swap_utils11.c \
			swap.c push.c rotate.c r_rotate.c sorter.c check_args.c

INCLUDE_B	= get_next_line.h
SRCS_B		= get_next_line.c get_next_line_utils.c push_swap_utils.c checker.c \
			checker_utils.c check_args.c swap_bonus.c push_bonus.c \
			rotate_bonus.c r_rotate_bonus.c move_stack.c \
			push_swap_utils10.c push_swap_utils11.c

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRCS) -c
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus:		$(NAME_B)

$(NAME_B):	$(OBJS_B)
			$(CC) $(CFLAGS) $(SRCS_B) -c
			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all
