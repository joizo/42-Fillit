# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 00:08:04 by ofedoryc          #+#    #+#              #
#    Updated: 2018/08/14 17:11:56 by mpetruno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRC = ./src/
OBJ = ./obj/
INC = ./includes/
LIB_DIR = ./libft/

LIB = $(LIB_DIR)libft.a

FILES = ft_checker.c \
		ft_error.c \
		ft_tetr_checker.c \
		tetr.c \
		map.c \
		solver.c \
		main.c

S_FILES = $(addprefix $(SRC), $(FILES))

O_FILES = $(addprefix $(OBJ), $(FILES:.c=.o))

H_FILES = $(INC)fillit.h $(LIB_DIR)libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB) $(H_FILES) $(O_FILES)
	@echo "Compiling fillit..."
	@$(CC) $(O_FILES) $(LIB) $(FLAGS) -I $(INC) -I $(LIB_DIR) -o $(NAME)
	@echo "Finished."

$(LIB):
	make -C $(LIB_DIR) -silent

$(OBJ)%.o: $(SRC)%.c
	@mkdir -p $(OBJ)
	@$(CC) -c $^ $(FLAGS) -I $(INC) -I $(LIB_DIR) -o $@

clean:
	rm -fr $(OBJ)
	make -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re comp
