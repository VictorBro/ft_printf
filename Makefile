# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 19:11:25 by vbronov           #+#    #+#              #
#    Updated: 2024/10/18 21:00:09 by vbronov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
SRCS := ft_printf.c \
		print_utils/utils.c \
		print_utils/ft_printchar.c \
		print_utils/ft_printstr.c \
		print_utils/ft_printptr.c \
		print_utils/ft_printnum.c \
		print_utils/ft_printunum.c \
		print_utils/ft_printhex.c
LIBFT_DIR := libft
BONUS_SRCS := 
CC := cc
CFLAGS := -Wall -Wextra -Werror
OBJS := $(SRCS:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a ft_printf.h
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(OBJS) $(BONUS_OBJS) $(LIBFT_DIR)/libft.a ft_printf.h
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f ft_test
	rm -f ft_test_bonus
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: ft_test
ft_test: $(NAME) main.c
	$(CC) -g main.c -L. -lftprintf -o ft_test


.PHONY: test
test: ft_test
	./ft_test


.PHONY: leak
leak: ft_test
	valgrind --leak-check=full ./ft_test
