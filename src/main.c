/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/02/19 00:19:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/fractol.h"
#include <limits.h>

int	init_fractal_from_cli(t_fractol_context *program, \
int argc, const char **argv)
{
	int	error_argc;

	error_argc = parse_input(program, argc, argv);
	if (error_argc)
	{
		if ((argc - error_argc) == 0)
			return (print_program_usage(argv[0]));
		return (print_invalid_option_msg(argv[0], \
			argv[argc - error_argc]));
	}
	set_potential_factor(&program->canvas.color_controls, 0);
	set_complex_number(&program->canvas.viewport, -1.5, 1);
	program->canvas.pixel_size = \
		calculate_pixel_size(&program->canvas.viewport, 1.5, WINDOW_WIDTH);
	program->animation_time = 0;
	set_base_color(&program->canvas.color_controls, 255, 127, 152);
	set_color_factor(&program->canvas.color_controls, 1, \
		0.34004648219, 0.17965377284);
	set_distance_estimator_settings(&program->canvas.estimator, 0.0005, 200);
	return (EXIT_SUCCESS);
}

t_fractol_context	*init_program(t_fractol_context *program)
{
	program->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, \
		"fractol", true);
	if (!(program)->mlx)
	{
		return (NULL);
	}
	mlx_set_window_limit(program->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, \
		INT_MAX, INT_MAX);
	program->canvas.image = mlx_new_image(program->mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT);
	if (!program->canvas.image)
	{
		mlx_terminate(program->mlx);
		return (NULL);
	}
	program->controls = 0;
	program->painter_func = &paint_fractal;
	program->painter.animation.speed = 100;
	return (program);
}

int	main(int argc, const char **argv)
{
	t_fractol_context	program;

	if (!(!init_fractal_from_cli(&program, argc, argv) \
		&& init_program(&program) && !malloc_distance_map(&program.canvas)))
	{
		exit(EXIT_FAILURE);
	}
	default_canvas_bounds(&program.canvas);
	mlx_image_to_window(program.mlx, program.canvas.image, 0, 0);
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
