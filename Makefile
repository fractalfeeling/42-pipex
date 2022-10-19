# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 14:30:57 by lwee              #+#    #+#              #
#    Updated: 2022/10/19 16:17:30 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FILES := utils get_next_line pipex

SRC_DIR = ./src
OBJ_DIR = ./src
INC_DIR = ./inc
LIB_DIR = ./ft_printf

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99 -I $(INC_DIR)

AR = ar rcs
RM = rm -f

all: $(NAME)

$(OBJ): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/libftprintf.a ./$(NAME)
	$(CC) $ZZ

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o
	make clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
