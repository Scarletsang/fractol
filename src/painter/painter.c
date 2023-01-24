/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:53:12 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 17:40:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "limits.h"
#include "fractol_painter.h"

uint32_t	distance_to_color(double value)
{
	double	scaled;

	if (value == BORDER_VALUE)
	{
		return (0);
	}
	if (value == INSET_VALUE)
	{
		return (255);
	}
	scaled = fabs(value) * 10000;
	return ((uint8_t) scaled << 24 | (uint8_t) scaled << 16 \
		| (uint8_t) scaled << 8 | 255);
}

int	draw_mandelbrot(t_fractol_viewport *viewport, mlx_image_t *canvas)
{
	uint32_t			x;
	uint32_t			y;
	t_fractol_complex	z;
	t_fractol_complex	c;

	c.real = viewport->real_min;
	x = 0;
	while (x < canvas->width)
	{
		c.imaginary = viewport->imaginary_max;
		y = 0;
		while (y < canvas->height)
		{
			mlx_put_pixel(canvas, x, y,
				distance_to_color(
					mandelbrot_distance_estimator(&z, &c, 4, 100)));
			c.imaginary -= viewport->step;
			y++;
		}
		c.real += viewport->step;
		x++;
	}
	return (0);
}

t_fractol_viewport	*init_mandelbrot(t_fractol_viewport *viewport)
{
	viewport->real_min = -1.5;
	viewport->imaginary_max = 0.14;
	viewport->step = 0.0002;
	return (viewport);
}

t_fractol_viewport	*calc_range(t_fractol_viewport *viewport, \
mlx_image_t *canvas)
{
	viewport->imaginary_min = viewport->imaginary_max - \
		(viewport->step * canvas->height);
	viewport->real_max = viewport->real_min + \
		(viewport->step * canvas->width);
	return (viewport);
}
