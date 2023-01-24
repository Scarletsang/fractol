/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:53:12 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 23:37:00 by htsang           ###   ########.fr       */
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
	uint32_t			x;
	uint32_t			y;
	t_fractol_complex	z;
	t_fractol_complex	c;
	uint32_t			*pixels;

	c.imaginary = viewport->imaginary_max;
	y = viewport->canvas->height;
	pixels = (uint32_t *) viewport->canvas->pixels;
	while (y-- > 0)
	{
		c.real = viewport->real_min;
		x = viewport->canvas->width;
		while (x-- > 0)
		{
			*pixels = distance_to_color(
					mandelbrot_distance_estimator(&z, &c, \
						viewport->step * BORDER_THICKNESS, 100));
			pixels++;
			c.real += viewport->step;
		}
		c.imaginary -= viewport->step;
	}
	return (0);
}
