# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmohamm <anmohamm@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 18:03:47 by anmohamm          #+#    #+#              #
#    Updated: 2024/02/03 15:36:30 by anmohamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
NORM = norminette
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
OBJS_DIR = objs/

SRCS = $(wildcard *.c)
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

re : fclean all

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

norm :
	@$(NORM) $(SRCS)

.PHONY : clean fclean re all bonus
