# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 14:30:57 by lwee              #+#    #+#              #
#    Updated: 2022/10/25 17:56:32 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99

FILES := pipex utils get_next_line

SRC_DIR = src
OBJ_DIR = src
INC_DIR = inc
INC += -I$(INC_DIR)

LIBNAME = libft
LIB_DIR = libft
LIB += -L$(LIB_DIR) -lft

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))
SRC_B = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(BONUS)))
OBJ_B = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(BONUS)))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

$(NAME): $(LIB_DIR)/$(LIBNAME) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INC) $(LIB)

$(LIB_DIR)/$(LIBNAME):
	make -C $(LIB_DIR)

bonus: all

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
