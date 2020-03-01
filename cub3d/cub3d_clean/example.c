/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 03:51:42 by lmarques          #+#    #+#             */
/*   Updated: 2020/03/01 16:12:52 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#define WIN_HEIGHT 1200
#define WIN_WIDTH 800

int	main(void)
{
	t_game	mlx; //Here I first create my struct that will contains all the "MLX stuff"
//	int		count_w;
	int		count_h;

	count_h = -1;
	//First you need to call mlx_init and store its return value.
	mlx.mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	//One more time with mlx_new_image
	mlx.mlx_img = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	/*
	 Now the important part :
	 mlx_get_data_addr will return a char* that is 4 times the (width * height) of your image.
	 Why so ? Let me explain : This char* will represent your image, pixel by pixel,
	 and the values of this array are the colors. That's why the array is 4 times bigger :
	 you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
	 But... it's not very convenient, right ? So here is my little trick : you cast
	 mlx_get_data_addr as an int* and store it in an int*.
	 This way, the array will have the exact same size as your window, and each index
	 will represent one complete color of a pixel !
	*/
	mlx.img_addr = (int *)mlx_get_data_addr(mlx.mlx_img, &mlx.bpp, &mlx.sl,
		&mlx.endian);
	/*
	 Now just a little example : here is a loop that will draw each pixels that
	 have an odd width in white and the ones that have an even width in black.
	*/
	while (++count_h < WIN_HEIGHT)
	{
				mlx.img_addr[count_h * WIN_WIDTH + 10] = 0xFFFFFF;
	}
	//Now you just have to print the image using mlx_put_image_to_window !
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.mlx_img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
