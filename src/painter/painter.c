/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/01/28 13:08:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	distance_to_color(double value)
{
	double	scaled;

	if (value == BORDER_VALUE)
	{
		return (get_rgba(255, 85, 85, 255));
	}
	if (value == INSET_VALUE)
	{
		return (0);
	}
	scaled = fabs(sin(value));
	return (get_rgba(255, 13, 152, 255 * scaled));
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
			canvas->pixels_start ++;
			painter.c.real += canvas->settings.pixel_size;
		}
		canvas->pixels_start += canvas->horizontal_offset;
		painter.c.imaginary -= canvas->settings.pixel_size;
	}
	return (0);
}
