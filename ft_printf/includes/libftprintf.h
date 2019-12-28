/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:53:59 by dsy               #+#    #+#             */
/*   Updated: 2019/12/28 00:02:23 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

extern int		g_ret;

typedef struct	s_field {

	char		flags[4];
	int			width;
	int			precision;
}				t_field;

size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				nb_digit(int c);
int				pars(char *str);
int				count_digit(int nb, char c);
int				is_conversion(char c);
int				is_present(char *str, char c);
int				flags(char c);
t_field			check_star(char *str, va_list args);
t_field			is_balise(char *str, va_list args);
int				i_conversion(va_list params, char type, t_field field);
int				s_conversion(va_list params, char type, t_field field);
int				x_conversion(va_list params, char type, t_field field);
int				p_conversion(va_list params, char type, t_field field);
int				ft_printf(const char *format, ...);
unsigned long	ft_power(unsigned long x, unsigned long y);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int n);
void			ft_putnbr_x(unsigned long value, char c);
void			print_balise_nb(int nb, char c, t_field field, int len);
void			print_balise_str(char *str, t_field field);
void			print_balise_char(char c, t_field field);
void			print_balise_add(unsigned long p, char c, t_field field);
int				pars_decimal(char *str);
int				pars_hexa(char *str);
int				pars_char_n_add(char *str);
int				pars_str(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
