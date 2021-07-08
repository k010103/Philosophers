# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 15:24:29 by junmkang          #+#    #+#              #
#    Updated: 2021/07/08 21:30:06 by junmkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

INCLUDE_DIR = ./includes/

SRCS_DIR = ./srcs/
SRCS_NAME = \
	main.c \
	ft_utils.c \
	philo_utils.c \
	info_init.c \
	philo_free.c \
	philo_init.c \
	philo_loop.c \
	philo_monitor.c \
	phlio_forks.c \
	philo_eat.c \
	philo_sleep.c \
	philo_think.c \
	print_msg.c

CC = gcc
RM = rm -rf
# FLAG = -Wall -Wextra -Werror -fsanitize=address -I $(INCLUDE_DIR)
FLAG = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
# FLAG = -Wall -Wextra -I $(INCLUDE_DIR)

# Color
CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m
CL_RED = \e[31m
CL_ZERO = \e[0m
CL_L_YELLOW = \e[93m
CL_L_BLUE = \e[94m

LF = \e[1K\r$(NO_COLOR)

BASIC = \
	$(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJ_DIR = objs

vpath %.c $(SRCS_DIR)

# OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(BASIC:.c=.o)))
OBJS = $(BASIC:.c=.o)

# ========================================================================

all : $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@$(CC) $(FLAG) -o $(NAME) $(OBJS)
	@printf "$(LF)$(CL_BOLD) 🍝 $(CL_ZERO)$(CL_BOLD)MAKE PHILO 🍝\n"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

%.o : %.c
	@$(CC) $(FLAG) -c $< -o $@
	@printf "$(LF) $(CL_RED) 🚧 Create $(CL_ZERO)$(CL_L_YELLOW)%-33.33s" $@

norm :
	norminette $(INCLUDE_DIR) $(SRCS_DIR)
	@printf "$(CL_BOLD) 🥳 norm 에 걸리는게 없대. 🥳\n"

clean :
	@$(RM) $(OBJS) $(OBJ_DIR)
	@printf "$(CL_L_BLUE) 💀 objs 가 지워졌어요. 💀\n"

fclean : clean
	@$(RM) $(NAME) $(LIBFT_NAME)
	@printf "$(CL_L_BLUE) 💀 philo 가 지워졌어요. 💀\n"

re : fclean all
	@printf "$(CL_BOLD) 🍝 re 가 진행되었어요. 🍝\n"
