# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:13:55 by tjoyeux           #+#    #+#              #
#    Updated: 2023/11/20 11:25:41 by tjoyeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $@ $^

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

