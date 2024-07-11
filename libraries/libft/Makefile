# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 14:20:21 by btoksoez          #+#    #+#              #
#    Updated: 2024/07/11 12:23:40 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
RM = rm -rf

SRC = ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c		\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c		\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_striteri.c	\
		ft_putnbr_fd.c	\
		ft_putnbr_base.c	\
		ft_printf.c		\
		ft_print_hex.c	\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\

# Colours
CYAN = \033[1;36m
ORANGE = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "$(CYAN)make$(RESET)   libft $(GREEN)[OK]$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(ORANGE)$@$(RESET)  libft $(GREEN)[OK]$(RESET)"

fclean:
	@$(RM) $(NAME)
	@echo "$(RED)$@$(RESET) libft $(GREEN)[OK]$(RESET)"

re: fclean all

.PHONY: all clean fclean re

