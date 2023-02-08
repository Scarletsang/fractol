/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/02/08 23:54:53 by htsang           ###   ########.fr       */
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
	init_fractal(&program, &mandelbrot_distance_estimator, -1.4, 0);
	mlx_image_to_window(program.mlx, program.canvas.image, 0, 0);
	paint_fractal(&program.canvas, &program.painter, program.fractal);
	program.controls = 0;
	program.painter.border_size = \
		program.canvas.settings.pixel_size * program.canvas.settings.pixel_size * \
		program.canvas.settings.border_thickness * program.canvas.settings.border_thickness;
	program.painter.x = 0;
	program.painter.y = 0;
	program.painter.speed = 101;
	mlx_loop_hook(program.mlx, \
		(void (*)(void *)) fractol_translation_hook, &program);
	mlx_key_hook(program.mlx, (mlx_keyfunc) fractol_key_hook, &program);
	mlx_scroll_hook(program.mlx, (mlx_scrollfunc) fractol_scroll_hook, \
		&program);
	mlx_resize_hook(program.mlx, (mlx_resizefunc) fractol_resize_hook, \
		&program);
	mlx_loop(program.mlx);
	mlx_terminate(program.mlx);
	return (EXIT_SUCCESS);
}
