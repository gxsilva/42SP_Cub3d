# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 16:22:54 by lsilva-x          #+#    #+#              #
#    Updated: 2025/06/23 19:20:13 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DEFINES
NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
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
SRCS		:= $(addprefix $(SRCS_DIR), main.c)
OBJS		:= $(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)/%.o,$(SRCS))

# MACROS
NO_PRINT	:= --no-print-directory

BOLD = \033[1m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
GREEN := \033[1;32m
END := \033[0m

# all: gnl libmlx libft $(NAME)
# $(NAME): $(OBJS)
# 	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
# 	@echo "🧊$(GREEN) Done!$(END)"
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

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(GNL_DIR) clean $(NO_PRINT) > /dev/null
	@make -C $(LIBFT_DIR) clean $(NO_PRINT) > /dev/null
	@echo "$(GREEN)🧹 Cleaned object files$(END)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)/build
	@make -C $(GNL_DIR) fclean $(NO_PRINT) > /dev/null
	@make -C $(LIBFT_DIR) fclean $(NO_PRINT) > /dev/null
	@echo "$(GREEN)🧹 $(RED)Full clean complete!$(END)"


	
re: fclean all

# LIBRAYS



# libmlx:
# 	@cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null 2>&1 && \
# 		make -C $(MLX_DIR)/build -j4 $(NO_PRINT) > /dev/null 2>&1
# 	@echo "MLX Compiled"

# gnl:
# 	@make -s -C $(GNL_DIR)
# 	@echo "GNL Compiled"

# libft:
# 	@make -s -C $(LIBFT_DIR) $(NO_PRINT)
# 	@echo "Libft Compiled"

.PHONY: libmlx gnl all clean fclean re

default: all