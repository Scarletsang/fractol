/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 14:15:24 by htsang           ###   ########.fr       */
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

int	draw_mandelbrot(t_fractol_viewport *viewport)
{
	viewport->math.c.imaginary = viewport->math.imaginary_max;
	viewport->painter.y = viewport->painter.height;
	while (viewport->painter.y-- > 0)
	{
		viewport->math.c.real = viewport->math.real_min;
		viewport->painter.x = viewport->painter.width;
		while (viewport->painter.x-- > 0)
		{
			*viewport->painter.pixels = distance_to_color(
					mandelbrot_distance_estimator(&viewport->math.z, \
						&viewport->math.c, viewport->painter.pixel_size \
						* BORDER_THICKNESS, 100));
			viewport->painter.pixels++;
			viewport->math.c.real += viewport->painter.pixel_size;
		}
		viewport->math.c.imaginary -= viewport->painter.pixel_size;
	}
	return (0);
}

t_fractol_context	*init_mandelbrot(t_fractol_context *program)
{
	program->viewport.painter.pixel_size = 0.0002;
	program->viewport.painter.height = program->canvas->height;
	program->viewport.painter.width = program->canvas->width;
	set_viewport_boundaries(program, -1.4, 0);
	return (set_painter_pixels(program, 0));
}
