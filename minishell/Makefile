NAME := minishell

LIB_FT := libft/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS :=
PFLAGS := -Iinclude -Ilibft

SRC_OTHER := main.c display.c msh_control.c utils.c builtins/builtins_1.c \
			 init_struct.c builtins/builtins_2.c builtins/builtins_runner.c \
			 list_utils.c free.c envp.c\

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
	stty -echoctl 

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
	rm -rf $(BUILD_PATH)

FORCE:

.PHONY: all, clean, fclean, re
