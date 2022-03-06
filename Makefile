# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:45:47 by nprimo            #+#    #+#              #
#    Updated: 2022/03/06 17:30:23 by nprimo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --quiet

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

NAME = philo

SRC = src
OBJ = obj
INC = inc
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(wildcard $(OBJ)/*.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all
