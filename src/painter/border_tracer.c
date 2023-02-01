/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 15:53:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

int32_t	*moore_neighbors(t_fractol_painter *painter, t_fractol_func fractal)
{
	
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
