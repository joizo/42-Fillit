# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 00:08:04 by ofedoryc          #+#    #+#              #
#    Updated: 2018/08/14 20:49:37 by mpetruno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

LIB_DIR = ./libft/

LIB = $(LIB_DIR)libft.a

FILES = ft_checker.c \
		ft_error.c \
		ft_tetr_checker.c \
		tetr.c \
		map.c \
		solver.c \
		main.c

O_FILES = $(FILES:.c=.o)

H_FILES = fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB) $(H_FILES) $(O_FILES)
	@echo "Compiling fillit..."
	@$(CC) $(O_FILES) $(LIB) $(FLAGS) -I $(LIB_DIR) -o $(NAME)
	@echo "Finished."

$(LIB):
	make -C $(LIB_DIR) -silent

%.o: %.c
	@$(CC) -c $^ $(FLAGS) -I $(LIB_DIR) -o $@

clean:
	rm -f $(O_FILES)
	make -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re comp
