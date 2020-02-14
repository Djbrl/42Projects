/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:24:47 by dsy               #+#    #+#             */
/*   Updated: 2020/02/14 17:03:59 by dsy              ###   ########.fr       */
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

#include "libft/libft.h"

typedef struct	s_mlx
{
	void		*mlx_ptr:NULL;
	void		*win_ptr:NULL;
	void		*mlx_img:NULL;
	int			*img_addr:NULL;
}				t_mlx;

typedef	struct	s_keys
{
	int			a:KEY_A;
	int			s:KEY_S;
	int			d:KEY_D;
	int			f:KEY_F;
	int			h:KEY_H;
	int			g:KEY_G;
	int			z:KEY_Z;
	int			x:KEY_X;
	int			c:KEY_C;
	int			v:KEY_V;
	int			b:KEY_B;
	int			q:KEY_Q;
	int			w:KEY_W;
	int			e:KEY_E;
	int			r:KEY_R;
	int			y:KEY_Y;
	int			t:KEY_T;
	int			one:KEY_ONE;
	int			two:KEY_TWO;
	int			three:KEY_THREE;
	int			four:KEY_FOUR;
	int			six:KEY_SIX;
	int			five:KEY_FIVE;
	int			nine:KEY_NINE;
	int			seven:KEY_SEVEN;
	int			eight:KEY_EIGHT;
	int			zero:KEY_ZERO;
	int			brace_r:KEY_BRACE_R;
	int			o:KEY_O;
	int			u:KEY_U;
	int			brace_l:KEY_BRACE_L;
	int			i:KEY_I;
	int			p:KEY_P;
	int			l:KEY_L;
	int			j:KEY_J;
	int			k:KEY_K;
	int			semi:KEY_SEMI;
	int			n:KEY_N;
	int			m:KEY_M;
	int			tab:KEY_TAB;
	int			esc:KEY_ESC;
	int			plus:KEY_PLUS;
	int			minus:KEY_MINUS;
	int			left:KEY_LEFT;
	int			right:KEY_RIGHT;
	int			down:KEY_DOWN;
	int			up:KEY_UP;
}				t_keys;

typedef	struct	s_data
{
	int			b;
	t_mlx		mlx;
	t_keys		keys;
}				t_data;

#endif
