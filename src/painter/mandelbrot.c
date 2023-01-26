/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 00:51:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

uint32_t	distance_to_color(double value)
{
	double	scaled;

	if (value == BORDER_VALUE)
	{
		return (0 | 255);
	}
	if (value == INSET_VALUE)
	{
		return (0 | (255 & 0xFF));
	}
	scaled = sin(value) * 100;
	return (148 << 24 | (uint8_t) scaled << 16 \
		| (uint8_t) scaled << 8 | (255 & 0xFF));
}

int	draw_mandelbrot(t_fractol_canvas *canvas)
{
	t_fractol_complex	z;

	canvas->c.imaginary = canvas->top_left_corner.imaginary;
	canvas->y = canvas->height;
	while (canvas->y-- > 0)
	{
		canvas->c.real = canvas->top_left_corner.real;
		canvas->x = canvas->width;
		while (canvas->x-- > 0)
		{
			*canvas->pixels = distance_to_color(
					mandelbrot_distance_estimator(&z, \
						&canvas->c, canvas->pixel_size \
						* BORDER_THICKNESS, 100));
			canvas->pixels++;
			canvas->c.real += canvas->pixel_size;
		}
		canvas->pixels += canvas->left_right_offset;
		canvas->c.imaginary -= canvas->pixel_size;
	}
	return (0);
}

t_fractol_context	*init_mandelbrot(t_fractol_context *program)
{
	program->canvas.pixel_size = 0.00002;
	program->canvas.left_right_offset = 0;
	set_viewport(program, -1.4, 0);
	set_canvas_dimension(program, program->image->width, \
		program->image->height);
	set_canvas_top_left_corner(program, 0, 0);
	return (set_canvas_pixels(program, 0));
}
