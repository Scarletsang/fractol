/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 14:15:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	distance_to_color(double value)
{
	if (value == BORDER_VALUE)
	{
		return (get_rgba(255, 85, 85, 255));
	}
	if (value == INSET_VALUE)
	{
		return (0);
	}
	return (get_rgba(255 * value, 13, 152, 255));
}

void	init_painter(t_fractol_painter *painter, t_fractol_canvas *canvas)
{
	painter->c.imaginary = canvas->complex_start.imaginary;
	painter->border_size = \
		canvas->settings.pixel_size * canvas->settings.pixel_size * \
		canvas->settings.border_thickness * canvas->settings.border_thickness;
}

int	paint_fractal(t_fractol_canvas *canvas, mlx_image_t *image, \
t_fractol_func fractal)
{
	t_fractol_painter	painter;

	init_painter(&painter, canvas);
	painter.y = canvas->start_y;
	while (painter.y < canvas->end_y)
	{
		painter.c.real = canvas->complex_start.real;
		painter.x = canvas->start_x;
		while (painter.x < canvas->end_x)
		{
			mlx_put_pixel(image, painter.x, painter.y, \
					distance_to_color(
					fractal(&canvas->z, &painter.c, \
						painter.border_size, canvas->settings.iteration)));
			painter.c.real += canvas->settings.pixel_size;
			painter.x++;
		}
		painter.c.imaginary -= canvas->settings.pixel_size;
		painter.y++;
	}
	return (0);
}
