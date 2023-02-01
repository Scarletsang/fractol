/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_calculator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:10:43 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 14:11:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

t_fractol_context	*calculate_left_translation(t_fractol_context *program, \
uint32_t delta)
{
	t_fractol_canvas	*canvas;
	t_fractol_complex	*viewport;

	canvas = &program->canvas;
	viewport = &program->viewport;
	move_viewport_real(canvas, viewport, delta, -1);
	set_canvas_complex_start(canvas, viewport, 0, 0);
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, delta, program->image->height);
	return (program);
}

t_fractol_context	*calculate_right_translation(t_fractol_context *program, \
uint32_t delta)
{
	t_fractol_canvas	*canvas;
	t_fractol_complex	*viewport;

	canvas = &program->canvas;
	viewport = &program->viewport;
	set_canvas_complex_start(canvas, viewport, \
		program->image->width * canvas->settings.pixel_size, 0);
	move_viewport_real(canvas, viewport, delta, 1);
	set_canvas_start(canvas, program->image->width - delta, 0);
	set_canvas_end(canvas, program->image->width, program->image->height);
	return (program);
}

t_fractol_context	*calculate_down_translation(t_fractol_context *program, \
uint32_t delta)
{
	t_fractol_canvas	*canvas;
	t_fractol_complex	*viewport;

	canvas = &program->canvas;
	viewport = &program->viewport;
	set_canvas_complex_start(canvas, viewport, 0, \
		program->image->height * canvas->settings.pixel_size);
	move_viewport_imaginary(canvas, viewport, delta, -1);
	set_canvas_start(canvas, 0, program->image->height - delta);
	set_canvas_end(canvas, program->image->width, program->image->height);
	return (program);
}

t_fractol_context	*calculate_up_translation(t_fractol_context *program, \
uint32_t delta)
{
	t_fractol_canvas	*canvas;
	t_fractol_complex	*viewport;

	canvas = &program->canvas;
	viewport = &program->viewport;
	move_viewport_imaginary(canvas, viewport, delta, 1);
	set_canvas_complex_start(canvas, viewport, 0, 0);
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, program->image->width, delta);
	return (program);
}

t_fractol_context	*resize_canvas(t_fractol_context *program, \
int32_t width, int32_t height)
{
	t_fractol_canvas	*canvas;

	canvas = &program->canvas;
	mlx_resize_image(program->image, width, height);
	set_canvas_complex_start(canvas, &program->viewport, 0, 0);
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, width, height);
	return (program);
}
