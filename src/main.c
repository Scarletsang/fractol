/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 00:32:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(void)
{
	t_fractol_context	*program;

	program = malloc(sizeof(t_fractol_context));
	if (!program)
	{
		exit(EXIT_FAILURE);
	}
	program->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, \
		"fractol", true);
	if (!program->mlx)
		exit(EXIT_FAILURE);
	program->image = mlx_new_image(program->mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT);
	if (!program->image)
	{
		mlx_terminate(program->mlx);
		exit(EXIT_FAILURE);
	}
	init_mandelbrot(program);
	draw_mandelbrot(&program->canvas);
	mlx_image_to_window(program->mlx, program->image, 0, 0);
	mlx_key_hook(program->mlx, &fractol_key_hook, program);
	mlx_resize_hook(program->mlx, &fractol_resize_hook, program);
	mlx_loop(program->mlx);
	mlx_terminate(program->mlx);
	free(program);
	return (EXIT_SUCCESS);
}
