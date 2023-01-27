/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:34 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 22:25:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

t_fractol_context	*set_viewport(t_fractol_context *program, \
double center_real, double center_imaginary)
{
	program->viewport.real = center_real - \
		(program->canvas.settings.pixel_size * program->image->width / 2);
	program->viewport.imaginary = center_imaginary + \
		(program->canvas.settings.pixel_size * program->image->height / 2);
	return (program);
}

t_fractol_context	*init_fractal(t_fractol_context *program, \
t_fractol_func fractal, double center_real, double center_complex)
{
	t_fractol_canvas	*canvas;

	canvas = &program->canvas;
	program->fractal = fractal;
	set_canvas_horizontal_offset(canvas, 0);
	set_viewport(program, center_real, center_complex);
	set_canvas_dimension(canvas, program->image->width, \
		program->image->height);
	set_canvas_complex_start(canvas, &program->viewport, 0, 0);
	set_canvas_pixels_start(canvas, program->image, 0);
	return (program);
}
