NAME = fractol
LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -g -Wall -Wextra -Werror
CC = cc
RM = rm -rf

SRC_DIR = sources
OBJ_DIR = objects

SRCS = color.c events.c main.c init.c atof.c julia.c mandelbrot.c parse_args.c render.c mandelbox.c

# Generate object file names by replacing .c with .o in SRCS
OBJ := $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Add SRC_DIR as a prefix to each source file
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))

# Rule to compile each .c file into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Detecting system
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR = libraries/minilibx-linux
	MLX = $(MLX_DIR)/libmlx_Linux.a
	MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lm -lz
	CFLAGS += -DLINUX
else
	MLX_DIR = libraries/minilibx-mac
	MLX = $(MLX_DIR)/libmlx.a
	MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/libmlx
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	CFLAGS += -DGL_SILENCE_DEPRECATION
endif

# Includes
INC = -I$(LIBFT_DIR) $(MLX_INC)

# Colours for output
CYAN = \033[1;36m
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

# Targets
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

$(LIBFT):
	@make -s -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@make -s -C $(MLX_DIR) --no-print-directory

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

.PHONY: all clean fclean re

