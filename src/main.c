/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 23:35:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol_context	*init_program(t_fractol_context *program)
{
	program->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, \
		"fractol", true);
	if (!(program)->mlx)
	{
		return (NULL);
	}
	program->canvas.image = mlx_new_image(program->mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT);
	if (!program->canvas.image)
	{
		mlx_terminate(program->mlx);
		return (NULL);
	}
	return (program);
}

int	main(int argc, const char **argv)
{
	t_fractol_context	program;

	if (!(!init_fractal_from_cli(&program, argc, argv) \
		&& init_program(&program)))
	{
		exit(EXIT_FAILURE);
	}
	init_canvas(&program.canvas);
	mlx_image_to_window(program.mlx, program.canvas.image, 0, 0);
	malloc_distance_map(&program.canvas);
	program.controls = 0;
	program.painter_func = &paint_fractal;
	program.painter.animation.speed = 100;
	program.painter_func(&program.canvas, &program.painter, program.fractal);
	paint_pixels_from_distance_map(&program.canvas);
	mlx_loop_hook(program.mlx, \
		(t_mlx_loop_func) fractol_draw_hook, &program);
	mlx_key_hook(program.mlx, (mlx_keyfunc) fractol_key_hook, &program);
	mlx_scroll_hook(program.mlx, (mlx_scrollfunc) fractol_scroll_hook, \
		&program);
	mlx_resize_hook(program.mlx, (mlx_resizefunc) fractol_resize_hook, \
		&program);
	mlx_loop(program.mlx);
	free(program.canvas.distance_map);
	mlx_terminate(program.mlx);
	return (EXIT_SUCCESS);
}
