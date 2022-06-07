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

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

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
	char		**r_key;
	char		**n_key;
	char		**so_key;
	char		**w_key;
	char		**e_key;
	char		**s_key;
	char		**f_key;
	char		**c_key;
	char		**map_key;
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
** PARSING FUNCTIONS
*/

/*
** MLX FUNCTIONS
*/

/*
** RAYCASTING
*/
#endif
