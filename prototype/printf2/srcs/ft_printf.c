/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:26:52 by dsy               #+#    #+#             */
/*   Updated: 2019/12/27 14:45:46 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** Main file, handles communication between the main function,
** and all the other functions.
*/

/*
** Tree function, checks which one is the current argument to handle,
** Sends the argument to the conversion function in charge of i.
*/
static int	which_arg(char arg, va_list params)
{
	if (arg == 'c' || arg == 's')
		if (!(s_conversion(params, arg)))
			return (0);
	if (arg == 'i' || arg == 'd' || arg == 'u')
		if (!(i_conversion(params, arg)))
			return (0);
	if (arg == 'p')
		if (!(p_conversion(params)))
			return (0);
	if (arg == 'x' || arg == 'X')
		if (!(x_conversion(params, arg)))
			return (0);
	return (1);
}

/*
** Prints text as the function goes through the string,
** When an argument is found, calls the tree function above,
** Then, continues to go through the string until \0. (repeat)
*/
static int	print_text(const char *str, va_list params)
{
	int i;
	int ret_val;

	i = 0;
	ret_val = 0;
	while (str[i])
	{
		ret_val++;
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if (str[i] == '%' && is_conversion(str[i + 1]))
		{
			if (!(which_arg(str[i + 1], params)))
				return (0);
			i = i + 2;
		}
		else
			write(1, &str[i++], 1);
	}
	return (ret_val);
}

/*
** Main function. Checks if the string to print exists,
** Then creates the list of arguments, 
** And calls the main printing function,
** Returning -1 if anything fails,
** Or the number of caracters printed if successful.
*/
int			ft_printf(const char *format, ...)
{
	int		i;
	int		return_value;
	va_list params;

	i = 0;
	return_value = 0;
	va_start(params, format);
	if (format[0] == '\0')
		return (0);
	if (!format)
		return (-1);
	if (!(return_value = print_text(format, params)))
		return (-1);
	va_end(params);
	return (return_value);
}
