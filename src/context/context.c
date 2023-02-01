/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:34 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 15:54:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

t_fractol_context	*set_viewport_center(t_fractol_context *program, \
double center_real, double center_imaginary)
{
	program->viewport.real = center_real - \
		(program->canvas.settings.pixel_size * program->image->width / 2);
	program->viewport.imaginary = center_imaginary + \
		(program->canvas.settings.pixel_size * program->image->height / 2);
	return (program);
}

t_fractol_context	*refresh_fractal(t_fractol_context *program)
{
	set_canvas_start(&program->canvas, 0, 0);
	set_canvas_end(&program->canvas, program->image->width, \
		program->image->height);
	set_canvas_complex_start(&program->canvas, &program->viewport, 0, 0);
	return (program);
}

t_fractol_context	*init_fractal(t_fractol_context *program, \
t_fractol_func fractal, double viewport_real, double viewport_imaginary)
{
	program->fractal = fractal;
	set_complex_number(&program->viewport, viewport_real, viewport_imaginary);
	return (refresh_fractal(program));
}
