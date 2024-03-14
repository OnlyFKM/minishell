NAME = minishell

CFLAGS = -g -Wextra -Wall -Werror
LIBFT = ./inc/libft
HEADERS = -I ./include -I /System/Volumes/Data/Users/$(USER)/.brew/Cellar/readline/8.2.7
INCLUDES = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline

SRCS =  src/minishell.c\
	src/utils/messages.c\
	src/utils/t_tokens.c\
	src/utils/list.c\
	src/utils/is.c\
	src/utils/libftplus.c\
	src/init/init.c\
	src/init/tokens.c\
	src/init/tokeneizer.c\
	src/init/tokeneizer2.c\
	src/tokendepure/expand.c\
	src/builtins/env.c\
	src/free/free.c

CC = gcc

OBJ_DIR = tmp
SRC_DIR = src

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

#OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(LIBFT)/libft.a $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	ar rcs minishell.a $(OBJS)
	@$(CC) -g $(CFLAGS) $(LIBFT)/libft.a $(OBJS) $(HEADERS) $(INCLUDES) -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/utils $(OBJ_DIR)/init $(OBJ_DIR)/builtins $(OBJ_DIR)/tokendepure $(OBJ_DIR)/free

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
