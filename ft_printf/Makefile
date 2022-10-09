# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 23:29:11 by lwee              #+#    #+#              #
#    Updated: 2022/09/01 02:16:44 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRC	= ft_check_flags ft_check_width ft_print_di ft_print_p \
		ft_print_x ft_check_precision ft_eval_format \
		ft_printf ft_print_s ft_check_specifier ft_print_c \
		ft_print_u ft_print_pct ft_nbr_fns
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

LIB_DIR = ../libft
LIB = $(LIB_DIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIB): 
	make -C $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

bonus: all
	
clean:
	make -C $(LIB_DIR) clean
	rm -rf *.o

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus lib
