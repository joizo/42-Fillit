# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 00:08:04 by ofedoryc          #+#    #+#              #
#    Updated: 2018/07/21 23:06:18 by ofedoryc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = ./*.c

LIBFT = ./libft/

HEAD = fillit.h

FLAGS = -Wall -Wextra -Werror

O_FILES = *.o

all: $(NAME)

$(NAME): lib
	gcc $(FILES) -I $(HEAD) -L $(LIBFT) -lft -o $(NAME)

lib:
	make -C $(LIBFT)

clean:
	rm -f $(O_FILES)
	make -C ./libft/ clean # -C убивает только файл

fclean: clean
	rm -f $(NAME)  # -f убивает только файл
	make -C ./libft/ fclean

re: fclean all

.PHONY: clean fclean all re lib
