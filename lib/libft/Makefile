CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = build/objects/
AR = ar rcs

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(addprefix ./src/, $(OBJ))
	mkdir -p bin
	$(AR) ./bin/$@ $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	mv $@ $(OBJ_DIR)

clean: 
	rm -rf $(addprefix $(OBJ_DIR), $(SRC:.c=.o)) $(addprefix $(OBJ_DIR), /$(SRC_BONUS:.c=.o)) 

fclean: clean
	rm -rf ./bin$(NAME) ./bin ./build

re: fclean all

.PHONY: all clean fclean re bonus