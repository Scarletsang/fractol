/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:10:43 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 00:47:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

t_fractol_context	*translate_viewport_left(t_fractol_context *program, \
uint32_t delta)
{
	move_viewport_real(program, delta, -1);
	set_canvas_top_left_corner(program, 0, 0);
	set_canvas_dimension(program, delta, program->image->height);
	program->canvas.left_right_offset = program->image->width - delta;
	set_canvas_pixels(program, 0);
	return (program);
}

t_fractol_context	*translate_viewport_right(t_fractol_context *program, \
uint32_t delta)
{
	set_canvas_top_left_corner(program, \
		program->image->width * program->canvas.pixel_size, 0);
	move_viewport_real(program, delta, 1);
	set_canvas_dimension(program, delta, program->image->height);
	program->canvas.left_right_offset = program->image->width - delta;
	set_canvas_pixels(program, program->image->width - delta);
	return (program);
}

t_fractol_context	*translate_viewport_down(t_fractol_context *program, \
uint32_t delta)
{
	set_canvas_top_left_corner(program, 0, \
		program->image->height * program->canvas.pixel_size);
	move_viewport_imaginary(program, delta, -1);
	set_canvas_dimension(program, program->image->width, delta);
	program->canvas.left_right_offset = 0;
	set_canvas_pixels(program, \
		program->image->width * (program->image->height - delta));
	return (program);
}

t_fractol_context	*translate_viewport_up(t_fractol_context *program, \
uint32_t delta)
{
	move_viewport_imaginary(program, delta, 1);
	set_canvas_top_left_corner(program, 0, 0);
	set_canvas_dimension(program, program->image->width, delta);
	program->canvas.left_right_offset = 0;
	set_canvas_pixels(program, 0);
	return (program);
}
