/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:34 by htsang            #+#    #+#             */
/*   Updated: 2023/01/29 22:41:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

void	set_controls(action_t *key_action, unsigned int *controls, \
t_fractol_control control)
{
	if (*key_action == MLX_PRESS || *key_action == MLX_REPEAT)
		*controls |= control;
	if (*key_action == MLX_RELEASE)
		*controls &= ~control;
}

t_fractol_context	*set_viewport_center(t_fractol_context *program, \
double center_real, double center_imaginary)
{
	program->viewport.real = center_real - \
		(program->canvas.settings.pixel_size * program->image->width / 2);
	program->viewport.imaginary = center_imaginary + \
		(program->canvas.settings.pixel_size * program->image->height / 2);
	return (program);
}

t_fractol_context	*init_fractal(t_fractol_context *program, \
t_fractol_func fractal, double viewport_real, double viewport_imaginary)
{
	t_fractol_canvas	*canvas;

	canvas = &program->canvas;
	program->fractal = fractal;
	set_canvas_horizontal_offset(canvas, 0);
	set_complex_number(&program->viewport, viewport_real, viewport_imaginary);
	set_canvas_dimension(canvas, program->image->width, \
		program->image->height);
	set_canvas_complex_start(canvas, &program->viewport, 0, 0);
	set_canvas_pixels_start(canvas, program->image, 0);
	return (program);
}
