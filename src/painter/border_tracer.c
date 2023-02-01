/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 02:13:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

int32_t	*moore_neighbors(t_fractol_painter *painter, t_fractol_func fractal)
{
	
}

int	border_trace_fractal(t_fractol_canvas *canvas, mlx_image_t *image, \
t_fractol_func fractal)
{
	t_fractol_painter	painter;
	double				border_size;

	painter.c.imaginary = canvas->complex_start.imaginary;
	border_size = canvas->settings.pixel_size * canvas->settings.pixel_size * \
		canvas->settings.border_thickness * canvas->settings.border_thickness;
	painter.y = 0;
	while (painter.y < canvas->height)
	{
		painter.c.real = canvas->complex_start.real;
		painter.x = 0;
		while (painter.x < canvas->width)
		{
			mlx_put_pixel(image, painter.x + canvas->horizontal_offset, \
				painter.y + canvas->vertical_offset, \
					distance_to_color(
					fractal(&painter.z, &painter.c, \
						border_size, canvas->settings.iteration)));
			painter.c.real += canvas->settings.pixel_size;
			painter.x++;
		}
		painter.c.imaginary -= canvas->settings.pixel_size;
		painter.y++;
	}
	return (0);
}
