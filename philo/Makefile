# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 16:56:50 by mgranate_ls       #+#    #+#              #
#    Updated: 2022/08/27 02:44:47 by mgranate_ls      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread

SRC =	main.c \
		validate_arguments.c \
		resources.c	\
		launcher.c \
		cleanse_program.c \
		actions.c
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ -l pthread

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re