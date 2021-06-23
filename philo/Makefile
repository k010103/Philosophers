# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 22:38:10 by junmkang          #+#    #+#              #
#    Updated: 2021/06/23 14:48:55 by junmkang         ###   ########.fr        #
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

# Color
CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m

BASIC = \
	$(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJS = $(BASIC:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@$(CC) $(FLAG) -o $(NAME) $(OBJS)
	@printf "$(CL_BOLD) 🍝 MAKE PHILO 🍝\n"

%.o : %.c
	@$(CC) $(FLAG) -c $*.c -o $@

clean :
	@$(RM) $(OBJS)
	@printf "$(CL_BOLD) 💀 *.o 가 지워졌어요. 💀\n"

fclean : clean
	@$(RM) $(NAME) $(LIBFT_NAME)
	@printf "$(CL_BOLD) 💀 모든게 지워졌어요. 💀\n"

re : fclean all
