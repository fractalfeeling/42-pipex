# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 14:30:57 by lwee              #+#    #+#              #
#    Updated: 2022/10/19 21:03:03 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99

FILES := get_next_line pipex utils

SRC_DIR = ./src/
OBJ_DIR = ./src/
INC_DIR = ./inc/
LIB_DIR = ./ft_printf/
LIB += -L $(LIB_DIR) -lftprintf
INC += -I $(INC_DIR)

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

AR = ar rcs
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	make re -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)

clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
