/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:06:45 by htsang            #+#    #+#             */
/*   Updated: 2023/02/13 15:49:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	name_matches(const char *fractal_name, char *expected)
{
	while (*fractal_name && *expected)
	{
		if (*fractal_name != *expected)
		{
			return (0);
		}
		fractal_name++;
		expected++;
	}
	if (*fractal_name || *expected)
	{
		return (0);
	}
	return (1);
}

double	calculate_pixel_size(t_fractol_complex *viewport, \
double end_real)
{
	return (fabs(viewport->real - end_real) / WINDOW_WIDTH);
}

int	init_fractal_from_cli(t_fractol_context *program, \
int argc, const char **argv)
{
	if (argc != 2)
		return (print_program_usage(argv[0]));
	else if (name_matches(argv[1], "mandelbrot"))
		program->fractal = &mandelbrot_distance_estimator;
	else if (name_matches(argv[1], "newton"))
		program->fractal = &newton_distance_estimator;
	else if (name_matches(argv[1], "julia"))
	{
		program->fractal = &julia_distance_estimator;
		set_complex_number(&program->canvas.z, -0.73, 0.18);
	}
	else
		return (print_invalid_option_msg(argv[0], argv[1]));
	program->program_name = argv[0];
	set_complex_number(&program->canvas.viewport, -1.5, 1);
	set_canvas_settings(&program->canvas, 200, 0.0005);
	program->canvas.settings.pixel_size = \
		calculate_pixel_size(&program->canvas.viewport, 1.5);
	return (EXIT_SUCCESS);
}
