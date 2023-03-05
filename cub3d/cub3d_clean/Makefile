NAME := Cub3D

LIB_FT := lib/libft/libft.a
MLX := /mlx/libmlx.a
LIBS := $(LIB_FT) $(MLX)
LDFLAGS = -Llib/libft
LFLAGS = -lft -L./mlx -lmlx -framework OpenGL -framework AppKit
CC := cc
CFLAGS := -Wall -Wextra -ggdb
PFLAGS := -Iinclude -Ilib/libft

SRC_MLX_FUNC := control_functions.c\
	images.c\
	init_game.c\
	mlx_utils.c
SRC_MLX_FUNC := $(addprefix mlx_functions/,$(SRC_MLX_FUNC))

SRC_PARSER := load_map.c\
	parse_map.c\
	parse_map_key.c\
	parse_map_utils.c\
	parse_other_keys.c\
	parse_other_keys_extend_2.c\
	parse_other_keys_extend.c\
	parse_weird_maps.c
SRC_PARSER := $(addprefix parser/,$(SRC_PARSER))

SRC_RAYCASTING := init_raycasting.c\
	raycasting.c\
	raycasting_utils.c
SRC_RAYCASTING := $(addprefix raycasting/,$(SRC_RAYCASTING))

SRC_UTILS := free_array.c
SRC_UTILS := $(addprefix utils/, $(SRC_UTILS))

SRC_OTHER := main.c

SRC_PATH := src
SRC_NAME := $(SRC_MLX_FUNC)\
	$(SRC_PARSER)\
	$(SRC_RAYCASTING)\
	$(SRC_UTILS)\
	$(SRC_OTHER)

SRC := $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH := obj
OBJ_NAME := $(SRC_NAME:.c=.o)
OBJ := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INCDIR := include

BUILD_PATH := build
OBJ := $(addprefix $(BUILD_PATH)/,$(OBJ))

all: $(NAME)


$(NAME): $(OBJ) $(LIBS)
	$(CC) $(OBJ) $(LDFLAGS) $(LFLAGS) $(CFLAGS) -o $(NAME) 

$(BUILD_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@) 2>/dev/null || true
	@$(CC) $(CFLAGS) $(PFLAGS) -c $< -o $@

$(LIB_FT): FORCE
	make -C lib/libft

libft_clean:
	make -C lib/libft clean

libft_fclean:
	make -C lib/libft fclean

$(MLX): FORCE
	make -C mlx/

mlx_clean:
	make -C mlx/ clean

mlx_fclean:
	make -C mlx/ clean

lib_clean: libft_clean mlx_clean

lib_fclean: libft_clean mlx_clean

re: fclean all

clean: lib_clean
	rm -rf $(OBJ)
	rm -rf $(BUILD_PATH)/$(OBJ_PATH)

fclean : lib_fclean clean
	rm -rf $(NAME)

FORCE:

.PHONY: all, clean, fclean, re
