/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:24:47 by dsy               #+#    #+#             */
/*   Updated: 2020/02/21 20:40:46 by dsy              ###   ########.fr       */
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

# include "libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

/*
**	STRUCTURES
*/

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			*img_addr;
}				t_mlx;

typedef struct	s_map
{
	char		**r_key;
	char		**n_key;
	char		**so_key;
	char		**w_key;
	char		**e_key;
	char		**s_key;
	char		**f_key;
	char		**c_key;
	char		**map_key;
}				t_map;

typedef	struct	s_keys
{
	int			a:1;
	int			s:1;
	int			d:1;
	int			f:1;
	int			h:1;
	int			g:1;
	int			z:1;
	int			x:1;
	int			c:1;
	int			v:1;
	int			b:1;
	int			q:1;
	int			w:1;
	int			e:1;
	int			r:1;
	int			y:1;
	int			t:1;
	int			one:1;
	int			two:1;
	int			three:1;
	int			four:1;
	int			six:1;
	int			five:1;
	int			nine:1;
	int			seven:1;
	int			eight:1;
	int			zero:1;
	int			brace_r:1;
	int			o:1;
	int			u:1;
	int			brace_l:1;
	int			i:1;
	int			p:1;
	int			l:1;
	int			j:1;
	int			k:1;
	int			semi:1;
	int			n:1;
	int			m:1;
	int			tab:1;
	int			esc:1;
	int			plus:1;
	int			minus:1;
	int			left:1;
	int			right:1;
	int			down:1;
	int			up:1;
}				t_keys;

typedef	struct	s_data
{
	t_mlx		mlx;
	t_map		map;
}				t_data;

/*
** PARSING FUNCTIONS
*/
void			free_array(char **array);
void			free_map_struct(t_map *map);
void			free_mlx_struct(t_mlx *mlx);
void			init_mlx_struct(t_mlx *mlx);
char			**load_map_file(char *path);
char			*remove_spaces(char *line);
char			*fetch_file(char *path);

int				fill_map(t_map *map, char **loaded_file);
int				check_file_keys(char **loaded_file, t_map *map);
int				parse_map_file(char *path, t_map *map);

int				adjust_resolution(t_map *map);
int				check_map_borders(t_map *map, int row, int col);
int				check_map_player(t_map *map);
int				check_map_values(t_map *map);
int				check_keys_order(t_map *map, char **loaded_file);
int				check_keys_content(t_map *map, char **loaded_file);
int				check_res_key(t_map *map);
int				check_rgb_keys(t_map *map);
int				check_rgb_keys_2(t_map *map);
int				check_rgb_values(t_map *map);
int				check_map(t_map *map);
int				get_file_size(char *path);
int				get_cols(t_map *map);
int				get_rows(t_map *map);

/*
** MLX FUNCTIONS
*/

int				init_game(t_mlx *mlx, t_map *map);
#endif
