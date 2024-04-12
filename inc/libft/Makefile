# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 12:46:13 by yfang             #+#    #+#              #
#    Updated: 2024/04/11 19:19:40 by frcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS =  -Wall -Wextra -Werror
ARFLAGS = ar -rcs
REMOVE = rm -rf

SRC = src/ft_atoi.c\
	src/ft_atol.c\
	src/ft_bzero.c\
	src/ft_calloc.c\
	src/ft_isalnum.c\
	src/ft_isalpha_char.c\
	src/ft_isalpha.c\
	src/ft_isascii.c\
	src/ft_isdigit.c\
	src/ft_isprint.c\
	src/ft_itoa.c\
	src/ft_lstadd_back_bonus.c\
	src/ft_lstadd_front_bonus.c\
	src/ft_lstclear_bonus.c\
	src/ft_lstdelone_bonus.c\
	src/ft_lstiter_bonus.c\
	src/ft_lstlast_bonus.c\
	src/ft_lstmap_bonus.c\
	src/ft_lstnew_bonus.c\
	src/ft_lstsize_bonus.c\
	src/ft_memchr.c\
	src/ft_memcmp.c\
	src/ft_memcpy.c\
	src/ft_memmove.c\
	src/ft_memset.c\
	src/ft_num.c\
	src/ft_printf.c\
	src/ft_putchar_fd.c\
	src/ft_putendl_fd.c\
	src/ft_putnbr_fd.c\
	src/ft_putstr_fd.c\
	src/ft_split.c\
	src/ft_strchr.c\
	src/ft_strcmp.c\
	src/ft_strdup.c\
	src/ft_striteri.c\
	src/ft_strjoin.c\
	src/ft_strjoin_2.c\
	src/ft_strlcat.c\
	src/ft_strlcpy.c\
	src/ft_strlen.c\
	src/ft_strmapi.c\
	src/ft_strncmp.c\
	src/ft_strnstr.c\
	src/ft_strrchr.c\
	src/ft_strtrim.c\
	src/ft_substr.c\
	src/ft_tolower.c\
	src/ft_toupper.c\
	src/ft_words.c\
	src/get_next_line_bonus.c\
	src/get_next_line_utils_bonus.c\

OBJ = $(SRC:src/%.c=obj/%.o)

HEADERS = -I include

.PHONY: all clean fclean re

.SILENT: all $(NAME) $(OBJ) clean fclean re

VIOLET = \033[38;5;129m
RESET = \033[0m
U_LINE = \033[4m

all: $(NAME)

$(NAME): $(OBJ)
	$(ARFLAGS) $@ $(OBJ)
	echo "\n$(VIOLET)$(U_LINE)🌸 $(NAME): Compiled 🌸 $(RESET) \n"

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(REMOVE) obj

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all