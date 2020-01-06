/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:53:59 by dsy               #+#    #+#             */
/*   Updated: 2020/01/06 11:28:38 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

extern int		ret_val;

typedef struct	s_field {
	char		flags[4];
	size_t		width;
	size_t		precision;
	size_t		length;
}				t_field;

unsigned long	power(unsigned long x, int y);
void			ft_putnbr_x(unsigned long value, char type);
int				is_conversion(char c);
int				i_conversion(va_list params, char type);
int				s_conversion(va_list params, char type);
int				x_conversion(va_list params, char type);
int				p_conversion(va_list params);
void			percent_conversion();
int				ft_printf(const char *format, ...);
#endif
