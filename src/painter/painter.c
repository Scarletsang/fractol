/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:53:12 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 00:43:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "limits.h"
#include "fractol_painter.h"

uint32_t	distance_to_color(double value)
{
	return (0 | (uint8_t) fabs(value) * 255);
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
			// mlx_put_pixel(canvas, x, y,
				distance_to_color(
					mandelbrot_distance_estimator(&z, &c, 4, 100));
			c.imaginary -= viewport->imaginary_step;
			y++;
		}
		c.real += viewport->real_step;
		x++;
	}
	return (0);
}

t_fractol_viewport	*init_mandelbrot(t_fractol_viewport *viewport)
{
	viewport->real_min = -2;
	viewport->real_max = 0.5;
	viewport->imaginary_min = -1;
	viewport->imaginary_max = 1;
	return (viewport);
}

t_fractol_viewport	*calc_steps(t_fractol_viewport *viewport, \
mlx_image_t *canvas)
{
	viewport->imaginary_step = (viewport->imaginary_max \
		- viewport->imaginary_min) / canvas->height;
	viewport->real_step = (viewport->real_max - viewport->real_min) \
		/ canvas->width;
	return (viewport);
}
