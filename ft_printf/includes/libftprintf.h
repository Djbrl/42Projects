/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:53:59 by dsy               #+#    #+#             */
/*   Updated: 2020/01/11 20:33:48 by othabchi         ###   ########.fr       */
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

	char		flags[2];
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
int				check_precision(char *s, int check);
t_field			check_star(char *str, va_list args);
t_field			is_balise(char *str, va_list args);
void			nb_conversion(va_list params, char *str, char type,
																t_field field);
void			s_conversion(char *s, va_list params, char type, t_field field);
void			p_conversion(va_list params, char type, t_field field);
int				ft_printf(const char *format, ...);
long			ft_power(long x, long y);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int n);
void			ft_putnbr_x(long value, char c);
void			print_balise_nb(long nb, char c, t_field field, int len);
void			print_balise_str(char *s, char *str, t_field field, int len);
void			print_balise_char(char c, t_field field);
void			print_balise_add(unsigned long p, char c, t_field field);
void			print_balise_pct(t_field f);
int				pars_decimal(char *str);
int				pars_hexa(char *str);
int				pars_char_n_add(char *str);
int				pars_str(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
