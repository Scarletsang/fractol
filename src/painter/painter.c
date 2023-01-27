/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 22:31:02 by htsang           ###   ########.fr       */
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

int	paint_fractal(t_fractol_canvas *canvas, t_fractol_func fractal)
{
	t_fractol_painter	painter;

	painter.c.imaginary = canvas->complex_start.imaginary;
	painter.y = canvas->height;
	while (painter.y-- > 0)
	{
		painter.c.real = canvas->complex_start.real;
		painter.x = canvas->width;
		while (painter.x-- > 0)
		{
			*canvas->pixels_start = \
				distance_to_color(
					fractal(&painter.z, \
						&painter.c, canvas->settings.pixel_size \
						* canvas->settings.border_thickness, \
						canvas->settings.iteration));
			canvas->pixels_start++;
			painter.c.real += canvas->settings.pixel_size;
		}
		canvas->pixels_start += canvas->horizontal_offset;
		painter.c.imaginary -= canvas->settings.pixel_size;
	}
	return (0);
}
