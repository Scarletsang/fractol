/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/02/09 23:44:26 by htsang           ###   ########.fr       */
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

int32_t	main(void)
{
	t_fractol_context	program;

	if (!init_program(&program))
	{
		exit(EXIT_FAILURE);
	}
	set_canvas_settings(&program.canvas, 100, 0.003, 0.01);
	set_complex_number(&program.canvas.z, -1, 0.16);
	init_fractal(&program, &julia_distance_estimator, -1.4, 0);
	mlx_image_to_window(program.mlx, program.canvas.image, 0, 0);
	program.controls = 0;
	init_painter(&program.canvas, &program.painter);
	program.painter.animation.speed = 10000;
	program.painter.animation.border_trace_started = 0;
	program.painter_func(&program.canvas, &program.painter, program.fractal);
	mlx_loop_hook(program.mlx, \
		(t_mlx_loop_func) fractol_translation_hook, &program);
	mlx_key_hook(program.mlx, (mlx_keyfunc) fractol_key_hook, &program);
	mlx_scroll_hook(program.mlx, (mlx_scrollfunc) fractol_scroll_hook, \
		&program);
	mlx_resize_hook(program.mlx, (mlx_resizefunc) fractol_resize_hook, \
		&program);
	mlx_loop(program.mlx);
	mlx_terminate(program.mlx);
	return (EXIT_SUCCESS);
}
