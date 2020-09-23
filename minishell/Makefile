NAME := minishell

LIB_FT := libft/libft.a

CC := clang
#CFLAGS := -Wall -Wextra -ggdb
CFLAGS :=
PFLAGS := -Iinclude -Ilibft

SRC_OTHER := main.c builtins/builtins_1.c

SRC_PATH := src
SRC_NAME := $(SRC_OTHER)

OBJ_PATH := obj
OBJ_NAME := $(SRC_NAME:.c=.o)

INCDIR := include
BUILD_PATH := build

SRC := $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ := $(addprefix $(BUILD_PATH)/,$(OBJ))

all: $(NAME)


$(NAME): $(OBJ) $(LIB_FT)
	$(CC) $(OBJ) $(LIB_FT) $(CFLAGS) -o $(NAME) 

$(BUILD_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@) 2>/dev/null || true
	@$(CC) $(CFLAGS) $(PFLAGS) -c $< -o $@

$(LIB_FT): FORCE
	make -C libft

libft_clean:
	make -C libft clean

libft_fclean:
	make -C libft fclean

lib_clean: libft_clean 

lib_fclean: libft_clean 

re: fclean all

clean: lib_clean
	rm -rf $(OBJ)
	rm -rf $(BUILD_PATH)/$(OBJ_PATH)

fclean : lib_fclean clean
	rm -rf $(NAME)

FORCE:

.PHONY: all, clean, fclean, re
