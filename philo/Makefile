# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 15:24:29 by junmkang          #+#    #+#              #
#    Updated: 2021/06/28 20:39:05 by junmkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

INCLUDE_DIR = ./includes/

SRCS_DIR = ./srcs/
SRCS_NAME = \
	main.c \
	ft_utils.c \
	print_msg.c \
	philo_loop.c \
	philo_eat.c \
	philo_sleep.c \
	philo_die.c

CC = gcc
RM = rm -f
# FLAG = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
FLAG = -Wall -Wextra -I $(INCLUDE_DIR)

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

norm :
	norminette $(INCLUDE_DIR) $(SRCS_DIR)
	@printf "$(CL_BOLD) 🥳 norm 에 걸리는게 없대. 🥳\n"

clean :
	@$(RM) $(OBJS)
	@printf "$(CL_BOLD) 💀 *.o 가 지워졌어요. 💀\n"

fclean : clean
	@$(RM) $(NAME) $(LIBFT_NAME)
	@printf "$(CL_BOLD) 💀 philo 가 지워졌어요. 💀\n"

re : fclean all
	@printf "$(CL_BOLD) 🍝 re 가 진행되었어요. 🍝\n"
