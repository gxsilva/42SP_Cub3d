# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 17:06:29 by lsilva-x          #+#    #+#              #
#    Updated: 2025/06/23 17:17:17 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= gnl
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror
AR		:= ar rcs

SRCS_DIR	:= ./src/
BIN_DIR		:= ./bin
DIR_OBJ		:= ./objects

SRCS		:= $(addprefix $(SRCS_DIR), get_next_line.c get_next_line_utils.c)
OBJS		:= $(patsubst $(SRCS_DIR)%.c,$(DIR_OBJ)/%.o,$(SRCS))

all: $(BIN_DIR)/lib$(NAME).a

$(BIN_DIR)/lib$(NAME).a: $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(AR) $@ $^

$(DIR_OBJ)/%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all