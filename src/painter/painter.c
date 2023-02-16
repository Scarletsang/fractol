/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 23:30:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/painter.h"

void	calculate_distance_estimator_c(t_fractol_canvas *canvas, \
uint32_t x, uint32_t y)
{
	set_complex_number(&canvas->estimator.c, \
		canvas->viewport.real + \
			(canvas->pixel_size * x), \
		canvas->viewport.imaginary - \
			(canvas->pixel_size * y));
}

void	paint_pixel(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	calculate_distance_estimator_c(canvas, painter->x, painter->y);
	fractal(get_distance_map_point(canvas, painter->x, painter->y), \
		&canvas->estimator);
}

void	paint_pixels_from_distance_map(t_fractol_canvas *canvas)
{
	uint32_t			x;
	uint32_t			y;

	y = canvas->start_y;
	while (y < canvas->end_y)
	{
		x = canvas->start_x;
		while (x < canvas->end_x)
		{
			mlx_put_pixel(canvas->image, x, y, \
				distance_to_color( \
					get_distance_map_point(canvas, x, y), \
					&canvas->color_controls));
			x++;
		}
		y++;
	}
}
