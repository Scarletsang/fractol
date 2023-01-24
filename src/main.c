/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/01/25 00:03:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(void)
{
	mlx_t				*mlx;
	mlx_image_t			*canvas;
	t_fractol_viewport	viewport;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	canvas = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!canvas)
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	init_mandelbrot(&viewport, canvas);
	draw_mandelbrot(&viewport);
	mlx_image_to_window(mlx, canvas, 0, 0);
	mlx_key_hook(mlx, &fractol_key_hook, &viewport);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
