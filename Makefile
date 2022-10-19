# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 14:30:57 by lwee              #+#    #+#              #
#    Updated: 2022/10/19 20:07:12 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_DIR = ./src
OBJ_DIR = ./src
INC_DIR = ./inc
LIB_DIR = ./ft_printf
FTPRINTF = -L $(LIB_DIR) -lftprintf

FILES := utils get_next_line pipex

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99 -I $(INC_DIR)

AR = ar rcs
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make re -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(FTPRINTF) -o $(NAME)

clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
