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

# define ARG_ERR "Error\nPlease input a map file.\n"
# define FILE_EXT "Error\nBad map extension.\n"
# define FILE_ERR "Error\nCouldn't open map file.\n"
# define MLX_INIT_ERR "Error\nFailed to start MLX.\n"
# define MLX_WIN_ERR "Error\nFailed to start MLX window.\n"
# define MAP_INVALID "Error\nPlease input a valid map file.\n"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include "libft.h"
# include "../lib/mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

/*
**	STRUCTURES
*/

typedef struct	s_img
{
	void		*mlx_img;
	int			*img_addr;
	int			bpp;
	int			sl;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_color
{
    int R;
    int G;
    int B;
    int set;
}               t_color;

/*
typedef struct s_sprite
{
    double              x;
    double              y;
    double              dst;
    float               diff;
    float               size;
    float               y_c;
    float               y_s;
    struct  s_sprite    *next;
}   t_sprite;
*/

typedef struct  s_ray
{
    int         map_x;
    int         map_y;
    double      dist_x;
    double      dist_y;
    double      d_dist_x;
    double      d_dist_y;
    int         step_x;
    int         step_y;
    int         hit;
    int         side;
    double      wall_dist;
    int         wall_height;
//    t_sprite    *sprite;
    int         lower_pix;
    int         higher_pix;
    double      camera_x;
    double      rdir_x;
    double      rdir_y;
    int         tex_x;;
}               t_ray;

typedef struct	s_game
{
	/*
	** MLX RELATED
	*/ 
	void		*mlx_ptr;
	void		*win_ptr;
	void		*wall;
	void		*path;
	void		*player;
	void		*item;
	void		*exit;
	t_img		l;
	t_img		m;
	t_img		so;
	t_img		no;
	t_img		ea;
	t_img		we;
	t_color		floor;
	t_color		ceiling;
	t_img		sprite;
	t_img		gun;
	/*
	** PARSING
	*/ 
	char		**map;
	int			width;
	int			height;
	int			row;
	int			col;
	char		error;

	int			red;
	int			green;
	int			yellow;
	int			blue;
	int			color;
	/*
	** RAYCASTING
	*/ 
	double		pos_y;
	double		pos_x;
	char		pov;
	int			x;
	int			speed;
	int			drawStart;
	int			drawEnd;
	int			lineHeight;
	int			sideDistX;
	int			sideDistY;
	int			deltaDistX;
	int			deltaDistY;
	int			perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			mapX;
	int			mapY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldtime;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		oldDirX;
	double		oldPlaneX;
}				t_game;

/*
MLX FUNCTIONS
*/
int		esc_window(int key, void *params);
int		cross_window(int key, void *params);
int		key_stroke(int key, void *params);

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
