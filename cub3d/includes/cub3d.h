/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:05:29 by dsy               #+#    #+#             */
/*   Updated: 2020/02/12 17:40:56 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DF_H
# define CUB3D_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_field {

	char		flags[2];
	int			width;
	int			precision;
	int			error;
}				t_field;

char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
