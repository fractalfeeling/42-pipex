# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:07:48 by lwee              #+#    #+#              #
#    Updated: 2022/10/19 16:11:13 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99

NAME = libftprintf.a

FILES := ft_check_flags ft_check_width ft_print_di ft_print_p \
			ft_print_x ft_check_precision ft_eval_format \
			ft_printf ft_print_s ft_check_specifier ft_print_c \
			ft_print_u ft_print_pct ft_nbr_fns

SRC_DIR = .
OBJ_DIR = .
INC_DIR = ../inc
LIB_DIR = ../libft

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

AR = ar rcs
RM = rm -f

all: $(NAME)

$(OBJ): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/libft.a ./$(NAME)
	$(AR) $@ $^

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
