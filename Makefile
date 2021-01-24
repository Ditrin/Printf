# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 01:41:32 by cdanette          #+#    #+#              #
#    Updated: 2021/01/16 02:17:27 by cdanette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -c

SRCS = ft_fun_c.c \
        ft_fun_d.c \
        ft_printf.c \
        ft_fun_s.c \
        ft_fun_p.c

OBJ = $(patsubst %.c,%.o,$(SRCS))
LIBA = ./libft
#INCLUDES = ./includes

all: $(NAME)

$(NAME):
	make re -C $(LIBA)
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ) $(LIBA)/*.o
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBA)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBA)

re: fclean all

.PHONY: all clean fclean re
