#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 17:01:45 by vlehuger          #+#    #+#              #
#    Updated: 2014/01/25 16:52:56 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = ft_minishell2

SRCS = \
		main.c \
		array_management.c \
		ft_builtin/ft_exit.c \
		ft_builtin/ft_setenv.c \
		ft_builtin/ft_unsetenv.c \
		ft_cmd.c \
		ft_cmp_env.c \
		ft_exec.c \
		ft_exec_cmd.c \
		ft_get_args.c \
		ft_get_cmd.c \
		ft_get_env.c \
		ft_get_env_path.c \
		ft_get_params.c \
		ft_init_cmd.c \
		ft_separe.c \
		ft_shell.c \
		ft_split_trim.c \
		ft_test_exec_redir.c \
		ft_test_ft_functions.c \
		ft_test_path.c \
		ft_test_pipe.c \
		ft_test_redir.c \
		ft_valid_redir.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
	$(CC) -I includes/ -I libft/includes/ -o $@ -c $< $(CFLAGS)

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: clean
