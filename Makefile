# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 18:19:21 by lwee              #+#    #+#              #
#    Updated: 2022/10/09 19:18:13 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

FILES := 

FILES_DIR := $(addprefix $(SRC_DIR)/, $(FILES))

SRC := $(addsuffix .c, $(FILES_DIR))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Wextra -Werror -std=c99 -I $(INC_DIR)

MKDIR = mkdir -p
RMDIR = rmdir

all: $(NAME)

$(OBJ_DIR):
	$(MKDIR) $@

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
