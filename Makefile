# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 00:08:04 by ofedoryc          #+#    #+#              #
#    Updated: 2018/08/04 21:04:52 by mpetruno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FILES = ft_checker.c \
		ft_error.c \
		ft_global_checker.c \
		ft_tetr_checker.c \
		main.c

LIB = ./libft/libft.a

LIBFT = ./libft/

HEAD = fillit.h

FLAGS = -Wall -Wextra -Werror

O_FILES = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(O_FILES)
	@echo "Assempling executable..."
	$(CC) $(O_FILES) $(LIB) $(FLAGS) -I $(HEAD) -o $(NAME)
	@edho "End assembling"

$(LIB):
	make -C $(LIBFT)

%.o: %.c
	@echo "Compiling file... "
	$(CC) -c $^ $(FLAGS)
	@echo "End compiling"

clean:
	rm -f $(O_FILES)
	make -C ./libft/ clean # -C убивает только файл

fclean: clean
	rm -f $(NAME)  # -f убивает только файл
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re
