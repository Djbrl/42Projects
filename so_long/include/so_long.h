/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:57:22 by dsy               #+#    #+#             */
/*   Updated: 2022/06/03 15:57:24 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GREEN_COLOR "\033[0;32m"
# define YLW_COLOR "\033[0;33m"
# define RED_COLOR "\033[0;31m"
# define END_COLOR "\033[0m"

# define MLX_ON_DESTROY 17

# define ARG_ERR "Error\nPlease input a map file.\n"
# define FILE_EXT "Error\nBad map extension.\n"
# define FILE_ERR "Error\nCouldn't open map file.\n"
# define MLX_INIT_ERR "Error\nFailed to start MLX.\n"
# define MLX_WIN_ERR "Error\nFailed to start MLX window.\n"
# define MAP_INVALID "Error\nPlease input a valid map file.\n"

# define PLAYER_XPM "data/textures/player.xpm"
# define TILE_XPM "data/textures/tile.xpm"
# define WALL_XPM "data/textures/wall.xpm"
# define LOOT_XPM "data/textures/loot.xpm"
# define DOOR_XPM "data/textures/door.xpm"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# include "libft.h"
# include "../lib/mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <math.h>

# define PI 3.14159263
/*
**	STRUCTURES
*/

typedef struct s_img
{
	void		*mlx_img;
	char		*img_addr;
	int			bpp;
	int			sl;
	int			endian;
	int			width;
	int			height;
}				t_img;
/*
** MLX RELATED
*/
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		wall;
	t_img		path;

	t_img		player;
	t_img		player2;
	float		player2_x;
	float		player2_y;
	float		player2_dx;
	float		player2_dy;
	float		player2_a;

	t_img		item;
	t_img		exit;

	char		**map;
	int			width;
	int			height;

	int			score;
	int			items_left;
	int			player_x;
	int			player_y;
}				t_game;
/*
MLX FUNCTIONS
*/
int		esc_window(t_game *data);
int		cross_window(t_game *data);
int		key_stroke(int key, t_game *data);
void	draw_map(t_game *data);
void	create_image(t_img *img, t_game *data, \
	int resolution[2], int casecolor);
/*
PARSING
*/
int		check_map_config(char **map);
int		check_map_extension(char *path);
int		parse_map(char *map, t_game *data);
int		get_map_width(char **map);
int		get_map_heigth(char **map);
/*
UTILS
*/
int		exit_game(char *msg, t_game *data);
int		exit_error(char *err, t_game *data);
void	init_game_struct(t_game *data);
void	free_mlx_struct(t_game *data);
void	free_split(char **array);
#endif
