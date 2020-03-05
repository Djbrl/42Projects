/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:24:47 by dsy               #+#    #+#             */
/*   Updated: 2020/03/05 01:31:10 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

/*
**	STRUCTURES
*/

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			*img_addr;
	int			bpp;
	int			sl;
	int			endian;

	char		**r_key;
	char		**n_key;
	char		**so_key;
	char		**w_key;
	char		**e_key;
	char		**s_key;
	char		**f_key;
	char		**c_key;
	char		**map_key;
	int			x_res;
	int			y_res;
	int			row;
	int			col;
	char		error;

	char		pov;
	double		pos_x;
	double		pos_y;

	int			red;
	int			green;
	int			yellow;
	int			blue;
	int			color;

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
}				t_game;

/*
** PARSING FUNCTIONS
*/
void			free_array(char **array);
void			report_error(t_game *data);
void			free_map_struct(t_game *game);
void			free_mlx_struct(t_game *game);
void			init_game_struct(t_game *game);
char			**load_map_file(char *path, t_game *data);
char			*remove_spaces(char *line);
char			**rearrange_keys(char **parsed_file, int n);
char			*fetch_file(char *path);

int				fill_map(t_game *game, char **loaded_file);
int				check_file_keys(char **loaded_file, t_game *game);
int				parse_map_file(char *path, t_game *game);

int				go_through_valid_keys(char **valid_keys, char *key);
int				check_keys_exist(t_game *file);
int				adjust_resolution(t_game *game);
int				arrange_map(t_game *game);
int				find_longest_row(t_game *game);
int				check_map_borders(t_game *game, int row, int col);
int				check_map_player(t_game *game);
int				check_map_values(t_game *game);
int				check_keys_order(t_game *game, char **loaded_file);
int				check_keys_content(t_game *game, char **loaded_file);
int				check_res_key(t_game *game);
int				check_rgb_keys(t_game *game);
int				check_rgb_keys_2(t_game *game);
int				check_rgb_values(t_game *game);
int				check_map(t_game *game);
int				get_file_size(char *path);
int				get_cols(t_game *game);
int				get_rows(t_game *game);

/*
** MLX FUNCTIONS
*/
int				testinit_game(t_game *game);
int				get_player_data(t_game *game);
int				init_game(t_game *game);
int				drawVerline(int key, void *params);
int				basic_image(int key, void *params);
int				key_stroke(int key, void *params);
int				cross_window(int key, void *params);
int				esc_window(int key, void *params);
#endif
