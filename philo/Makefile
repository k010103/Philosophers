# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 22:38:10 by junmkang          #+#    #+#              #
#    Updated: 2021/06/22 02:40:43 by junmkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE_DIR = ./includes/

SRCS_DIR = ./srcs/
SRCS_NAME = \
	main.c \
	ft_utils.c \
	print_error_msg.c

CC = gcc
RM = rm -f
FLAG = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

BASIC = \
	$(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJS = $(BASIC:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAG) -c $*.c -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME) $(LIBFT_NAME)

re : fclean all
