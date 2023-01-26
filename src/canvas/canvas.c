/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 00:43:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_canvas.h"

t_fractol_context	*set_canvas_top_left_corner(t_fractol_context *program, \
double real_offset, double imaginary_offset)
{
	program->canvas.top_left_corner.real = \
		program->viewport.real + real_offset;
	program->canvas.top_left_corner.imaginary = \
		program->viewport.imaginary - imaginary_offset;
	return (program);
}

t_fractol_context	*set_canvas_dimension(t_fractol_context *program, \
uint32_t width, uint32_t height)
{
	program->canvas.width = width;
	program->canvas.height = height;
	return (program);
}

t_fractol_context	*set_canvas_pixels(t_fractol_context *program, \
uint32_t offset)
{
	program->canvas.pixels = \
		(uint32_t *)(program->image->pixels) + offset;
	return (program);
}

t_fractol_context	*resize_canvas(t_fractol_context *program, \
int32_t width, int32_t height)
{
	mlx_resize_image(program->image, width, height);
	program->canvas.left_right_offset = 0;
	set_canvas_top_left_corner(program, 0, 0);
	set_canvas_dimension(program, width, height);
	return (set_canvas_pixels(program, 0));
}
