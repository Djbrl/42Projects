/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:03:16 by dsy               #+#    #+#             */
/*   Updated: 2020/02/07 05:03:17 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

extern int		g_ret;

size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				nb_digit(int c);
int				pars(char *str);
int				count_digit(long nb, char c);
int				is_conversion(char c);
int				is_present(char *str, char c);
int				flags(char c);
int				check_precision(char *s, int check);
void			nb_conversion(va_list params, char type);
void			s_conversion(char *s, va_list params, char type);
void			p_conversion(va_list params, char type);
int				ft_printf(const char *format, ...);
long			ft_power(long x, long y);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(long n);
void			ft_putnbr_x(long value, char c);
int				pars_decimal(char *str);
int				pars_hexa(char *str);
int				pars_char_n_add(char *str);
int				pars_str(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
