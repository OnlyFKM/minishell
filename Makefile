NAME = minishell

CFLAGS = -g -Wextra -Wall -Werror
LIBFT = ./inc/libft
HEADERS = -I ./include -I /System/Volumes/Data/Users/$(USER)/.brew/Cellar/readline/8.2.7
INCLUDES = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline

SRCS =  src/main.c\
	src/utils/is.c\
	src/utils/libftplus.c\
	src/utils/list.c\
	src/utils/t_tokens.c\
	src/utils/utils.c\
	src/utils/welcome.c\
	src/tokendepure/agroup.c\
	src/tokendepure/expand_utils.c\
	src/tokendepure/expand.c\
	src/pipex/execution.c\
	src/pipex/heredoc.c\
	src/pipex/planner.c\
	src/pipex/utils_pipex.c\
	src/init/init.c\
	src/init/tokeneizer.c\
	src/init/tokeneizer2.c\
	src/init/tokens.c\
	src/free/final_free.c\
	src/free/free.c\
	src/builtins/basics.c\
	src/builtins/cd_utils.c\
	src/builtins/cd.c\
	src/builtins/echo.c\
	src/builtins/env.c\
	src/builtins/export.c\
	src/builtins/export_utils.c\
	src/builtins/unset.c\


CC = gcc

OBJ_DIR = tmp
SRC_DIR = src

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

#OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(LIBFT)/libft.a $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	#ar rcs	minishell.a $(OBJS)
	@$(CC) -g $(CFLAGS) $(LIBFT)/libft.a $(OBJS) $(HEADERS) $(INCLUDES) -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/utils $(OBJ_DIR)/init $(OBJ_DIR)/builtins $(OBJ_DIR)/tokendepure $(OBJ_DIR)/free $(OBJ_DIR)/pipex

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
