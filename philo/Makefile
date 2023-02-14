# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 00:24:53 by mgranate_ls       #+#    #+#              #
#    Updated: 2023/02/14 12:37:46 by mgranate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		$(SRC_DIR)/main.c 				\
			$(SRC_DIR)/validate_arguments.c \
			$(SRC_DIR)/resources.c			\
			$(SRC_DIR)/launcher.c 			\
			$(SRC_DIR)/cleanse_program.c 	\
			$(SRC_DIR)/init.c				\
			$(SRC_DIR)/time.c				\
			$(SRC_DIR)/death_cheaker.c		\
			$(SRC_DIR)/eat.c				\
			$(SRC_DIR)/print_message.c				

OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	srcs

OBJ_DIR		=	objs

NAME 		=	philo

INC			=	includes/

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g -I$(INC) -g -fsanitize=address #-fsanitize=thread

RM			=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -l pthread

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I /usr/local/include -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

valgrind:	re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --log-file=valgrind-out.txt ./philo

re: fclean all

.PHONY: clean all fclean re