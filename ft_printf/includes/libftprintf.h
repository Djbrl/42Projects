/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:53:59 by dsy               #+#    #+#             */
/*   Updated: 2019/12/04 03:27:21 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_field {

	char		flags[4];
	int		width;
	int		precision;
	int		length;
	int		error;
}			t_field;

int			count_digit(int nb, char c);
int			is_conversion(char c);
int			check_balise(char c);
t_field			is_balise(char *str, va_list args);
int			i_conversion(va_list params, char type, t_field field);
int			s_conversion(va_list params, char type, t_field field);
int			x_conversion(va_list params, char type, t_field field);
int			p_conversion(va_list params, char type, t_field field);
int			ft_printf(const char *format, ...);
unsigned long		ft_power(unsigned long x , unsigned long y);
void			ft_putnbr_x(unsigned long value, char c);
void			print_balise_nb(int nb, char c, t_field field);
void			print_balise_str(char *str, t_field field);
void			print_balise_char(char c, t_field field);
void			print_balise_add(unsigned long p, char c, t_field field);
int			pars_decimal(char *str);
int			pars_hexa(char *str);
int			pars_char(char *str);
int			pars_str(char *str);
#endif
