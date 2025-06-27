# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 16:22:54 by lsilva-x          #+#    #+#              #
#    Updated: 2025/06/27 14:14:13 by ailbezer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DEFINES
NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3 -O0
MLXFLAGS	:= -ldl -lglfw -lpthread -lm -lmlx42 -lft -lgnl

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

LIBS = -L$(MLX_DIR)/build -L$(LIBFT_DIR)/bin -L$(GNL_DIR)/bin

# FILES
SRCS		:= $(addprefix $(SRCS_DIR), \
	main.c \
	error/process_error.c \
	map/fill_map.c map/parse_map.c \
)

OBJS		:= $(patsubst $(SRCS)%.c,$(OBJ_DIR)/%.o,$(SRCS))

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
	@$(CC) $(CFLAGS) -c $< -o $@

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

debug: $(OBJS) $(GNL_LIB) $(LIBFT_LIB) $(MLX_LIB)
	@$(CC) $(CFLAGS) -D DEBUG_FLAG=1 $(HEADERS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $@
	@echo "$(GREEN)✅ $(BOLD)$(NAME) compiled debug successfully!$(END)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(GNL_DIR) clean $(NO_PRINT) > /dev/null
	@make -C $(LIBFT_DIR) clean $(NO_PRINT) > /dev/null
	@echo "$(GREEN)🧹 Cleaned object files$(END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f debug
	@rm -rf $(MLX_DIR)/build
	@make -C $(GNL_DIR) fclean $(NO_PRINT) > /dev/null
	@make -C $(LIBFT_DIR) fclean $(NO_PRINT) > /dev/null
	@echo "$(GREEN)🧹 $(RED)Full clean complete!$(END)"
	
re: fclean all

g: re
	@clear && $(VALGRIND) ./cub3D maps/good/cheese_maze.cub 
	@$(VALGRIND) ./cub3D maps/good/creepy.cub 
	@$(VALGRIND) ./cub3D maps/good/dungeon.cub 
	@$(VALGRIND) ./cub3D maps/good/library.cub 
	@$(VALGRIND) ./cub3D maps/good/matrix.cub 
	@$(VALGRIND) ./cub3D maps/good/sad_face.cub 
	@$(VALGRIND) ./cub3D maps/good/square_map.cub 
	@$(VALGRIND) ./cub3D maps/good/subject_map.cub 
	@$(VALGRIND) ./cub3D maps/good/test_map_hole.cub 
	@$(VALGRIND) ./cub3D maps/good/test_map.cub 
	@$(VALGRIND) ./cub3D maps/good/test_pos_bottom.cub 
	@$(VALGRIND) ./cub3D maps/good/test_pos_left.cub
	@$(VALGRIND) ./cub3D maps/good/test_pos_right.cub 
	@$(VALGRIND) ./cub3D maps/good/test_pos_top.cub 
	@$(VALGRIND) ./cub3D maps/good/test_textures.cub 
	@$(VALGRIND) ./cub3D maps/good/test_whitespace.cub 
	@$(VALGRIND) ./cub3D maps/good/works.cub
	
# b: re
# 	@clear && ./cub3D maps/bad/color_invalid_rgb.cub
# 	@./cub3D maps/bad/color_missing_ceiling_rgb.cub
# 	@./cub3D maps/bad/color_missing_floor_rgb.cub
# 	@./cub3D maps/bad/color_missing.cub 
# 	@./cub3D maps/bad/color_none.cub 
# 	@./cub3D maps/bad/empty.cub
# 	@./cub3D maps/bad/file_letter_end.cub
# 	@./cub3D maps/bad/filetype_missing 
# 	@./cub3D maps/bad/filetype_wrong.buc
# 	@./cub3D maps/bad/forbidden.cub 
# 	@./cub3D maps/bad/map_first.cub
# 	@./cub3D maps/bad/map_middle.cub
# 	@./cub3D maps/bad/map_missing.cub 
# 	@./cub3D maps/bad/map_only.cub
# 	@./cub3D maps/bad/map_too_small.cub
# 	@./cub3D maps/bad/player_multiple.cub
# 	@./cub3D maps/bad/player_none.cub 
# 	@./cub3D maps/bad/player_on_edge.cub
# 	@./cub3D maps/bad/textures_dir.cub 
# 	@./cub3D maps/bad/textures_duplicates.cub 
# 	@./cub3D maps/bad/textures_forbidden.cub 
# 	@./cub3D maps/bad/textures_invalid.cub
# 	@./cub3D maps/bad/textures_missing.cub 
# 	@./cub3D maps/bad/textures_none.cub
# 	@./cub3D maps/bad/textures_not_xpm.cub
# 	@./cub3D maps/bad/wall_hole_east.cub
# 	@./cub3D maps/bad/wall_hole_north.cub 
# 	@./cub3D maps/bad/wall_hole_south.cub 
# 	@./cub3D maps/bad/wall_hole_west.cub
# 	@./cub3D maps/bad/wall_none.cub
		 
.PHONY: libmlx gnl all clean fclean re g #b

default: all