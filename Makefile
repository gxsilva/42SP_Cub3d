# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 16:22:54 by lsilva-x          #+#    #+#              #
#    Updated: 2025/07/11 19:40:16 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DEFINES
NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3 -O0
MLXFLAGS	:= -ldl -lmlx42 -lglfw -lpthread -lm -lft -lgnl -fPIC

# DIRECTORIES
SRCS_DIR	:= src/
GNL_DIR		:= lib/GNL
LIBFT_DIR	:= lib/libft
MLX_DIR		:= lib/MLX42
OBJ_DIR		:= build/objects

# Headers
HEADERS := -I includes -I $(MLX_DIR)/include -I $(LIBFT_DIR)/includes -I $(GNL_DIR)/includes

# Library files
GNL_A		:= libgnl.a
LIBFT_A		:= libft.a
MLX_A		:= libmlx42.a

# LIBS
GNL_LIB		:= $(GNL_DIR)/bin/$(GNL_A)
LIBFT_LIB	:= $(LIBFT_DIR)/bin/$(LIBFT_A)
MLX_LIB		:= $(MLX_DIR)/build/$(MLX_A)

# DEBUG
DEBUG_OBJ_DIR = debug_objs
DEBUG_OBJS = $(SRCS:$(SRCS_DIR)%.c=$(DEBUG_OBJ_DIR)/%.o)
SH_PATH_DEBUG := ./scripts/run_leak.sh

LIBS = -L$(MLX_DIR)/build -L$(LIBFT_DIR)/bin -L$(GNL_DIR)/bin

# FILES
SRCS		:= $(addprefix $(SRCS_DIR), \
	main.c \
	error/process_error.c \
	map/file/fill_map.c \
	map/file/fill_file_struct.c \
	map/file/fill_file.c \
	map/file/fill_file_rgb.c \
	map/file/png_verify.c \
	map/map_struct/map_infos.c \
	map/map_struct/map_matrix.c \
	map/map_struct/parse_map.c \
	map/map_struct/validate_walls.c \
	map/map_struct/validate_walls_diag.c \
	map/minimap/minimap_utils.c \
	map/minimap/minimap.c \
	map/minimap/player_minimap.c \
	map/draw/dda.c \
	map/draw/draw_game_utils.c \
	map/draw/draw_game.c \
	map/draw/raycast.c \
	free/free_split.c \
	free/free_cube.c \
	free/free_cube_utils.c \
	utils/strlen_space.c \
	utils/format_path.c \
	utils/free_two.c \
	utils/get_cube.c \
	utils/print_color.c \
	utils/clean_static.c \
	utils/sanitaze_string.c \
	debug/file_debug.c \
	debug/parse_debug.c \
	debug/raytrace_debug.c \
	player/elapsed_player.c \
	player/init_player.c \
	player/state_player.c \
	mlx/mlx_hooks.c \
	mlx/mlx_mouse.c \
	mlx/mlx_initialize.c \
	mlx/utils_key_hooks.c \
)

OBJS		:= $(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)/%.o,$(SRCS))

# MACROS
NO_PRINT	:= --no-print-directory
VALGRIND	:= valgrind --quiet --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=all

BOLD = \033[1m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
GREEN := \033[1;32m
END := \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(GNL_LIB) $(LIBFT_LIB) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $@
	@echo "$(GREEN)✅ $(BOLD)$(NAME) compiled successfully!$(END)"
	
$(OBJ_DIR)/%.o: $(SRCS_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(MLX_LIB):
	@echo "$(BLUE)🛠️  Building MLX42...$(END)"
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null
	@make -C $(MLX_DIR)/build -j4 $(NO_PRINT) > /dev/null

$(LIBFT_LIB):
	@echo "$(CYAN)🛠️  Building libft...$(END)"
	@make -C $(LIBFT_DIR) $(NO_PRINT) > /dev/null

$(GNL_LIB):
	@echo "$(MAGENTA)🛠️  Building GNL...$(END)"
	@make -C $(GNL_DIR) $(NO_PRINT) > /dev/null

$(DEBUG_OBJ_DIR)/%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -D DEBUG_FLAG=1 $(HEADERS) -c $< -o $@

# debug: fclean $(OBJS) $(GNL_LIB) $(LIBFT_LIB) $(MLX_LIB)
# 	@$(CC) $(CFLAGS) -D DEBUG_FLAG=1 $(HEADERS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $@
# 	@echo "$(GREEN)✅ $(BOLD)$(NAME) compiled debug successfully!$(END)"

debug: $(DEBUG_OBJS) $(GNL_LIB) $(LIBFT_LIB) $(MLX_LIB)
	@$(CC) $(CFLAGS) -D DEBUG_FLAG=1 $(HEADERS) $(DEBUG_OBJS) $(LIBS) $(MLXFLAGS) -o debug_bin
	@echo "$(GREEN)✅ $(BOLD)Debug build successful!$(END)"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DEBUG_OBJ_DIR)
	@make -C $(GNL_DIR) clean $(NO_PRINT) > /dev/null
	@make -C $(LIBFT_DIR) clean $(NO_PRINT) > /dev/null
	@echo "$(GREEN)🧹 Cleaned object files$(END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f debug_bin
	@rm -rf $(MLX_DIR)/build
	@make -C $(GNL_DIR) fclean $(NO_PRINT) > /dev/null
	@make -C $(LIBFT_DIR) fclean $(NO_PRINT) > /dev/null
	@echo "$(GREEN)🧹 $(RED)Full clean complete!$(END)"
	
re: fclean all

norm:
	@echo "\n$(CYAN)=======$(END) $(GREEN)LIBFT$(END) $(CYAN)=======$(END)"
	@norminette lib/libft | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/libft/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(CYAN)=======$(END) $(GREEN)GNL$(END) $(CYAN)=======$(END)"
	@norminette lib/GNL | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/GNL/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(CYAN)=======$(END) $(GREEN)MANDATORY$(END) $(CYAN)=======$(END)"
	@norminette src | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/src/\x1b[1;33m&\x1b[0m/g'
	@echo "\n$(CYAN)=======$(END) $(GREEN)INCLUDES$(END) $(CYAN)=======$(END)"
	@norminette includes/ | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/includes/\x1b[1;36m&\x1b[0m/g'

leak: fclean debug
	@$(SH_PATH_DEBUG)

.PHONY: libmlx gnl all clean fclean re norm leak

default: all