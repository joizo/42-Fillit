# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 21:38:21 by ofedoryc          #+#    #+#              #
#    Updated: 2018/04/10 21:38:23 by ofedoryc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_lstmap.c ft_putnbr.c ft_strmap.c ft_lstnew.c \
  ft_putnbr_fd.c ft_strmapi.c ft_atoi.c  \
  ft_putstr.c ft_strncat.c ft_bzero.c \
  ft_putstr_fd.c ft_strncmp.c ft_memalloc.c \
  ft_strcat.c ft_strncpy.c ft_memccpy.c \
  ft_strchr.c ft_strnequ.c ft_isalnum.c ft_memchr.c \
  ft_strclr.c ft_strnew.c ft_isalpha.c ft_memcmp.c \
  ft_strcmp.c ft_strnstr.c ft_isascii.c ft_memcpy.c \
  ft_strcpy.c ft_strrchr.c ft_isdigit.c ft_memdel.c \
  ft_strdel.c ft_strsplit.c ft_isprint.c ft_memmove.c \
  ft_strdup.c ft_strstr.c  ft_memset.c \
  ft_strequ.c ft_strsub.c ft_itoa.c \
  ft_striter.c ft_strtrim.c ft_lstadd.c ft_putchar.c \
  ft_striteri.c ft_tolower.c ft_lstdel.c ft_putchar_fd.c \
  ft_strjoin.c ft_toupper.c ft_lstdelone.c ft_putendl.c \
  ft_strlcat.c ft_lstiter.c ft_putendl_fd.c ft_strlen.c \
  ft_c_int_num.c ft_pov_count.c ft_swap.c ft_abs_m.c ft_sqrt.c

OFILES = $(FILES:.c=.o)

HEADERS = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES) $(HEADERS)
	@ar rc $(NAME) $(OFILES)

$(OFILES): %.o:%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
