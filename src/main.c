/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 14:15:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int32_t	main(void)
{
	t_fractol_context	program;

	program.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, \
		"fractol", true);
	if (!program.mlx)
		exit(EXIT_FAILURE);
	program.canvas = mlx_new_image(program.mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT);
	if (!program.canvas)
	{
		mlx_terminate(program.mlx);
		exit(EXIT_FAILURE);
	}
	init_mandelbrot(&program);
	draw_mandelbrot(&program.viewport);
	mlx_image_to_window(program.mlx, program.canvas, 0, 0);
	mlx_key_hook(program.mlx, &fractol_key_hook, &program);
	mlx_resize_hook(program.mlx, &fractol_resize_hook, &program);
	mlx_loop(program.mlx);
	mlx_terminate(program.mlx);
	return (EXIT_SUCCESS);
}
