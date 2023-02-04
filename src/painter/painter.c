/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 02:39:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

void	calculate_painter_c(t_fractol_canvas *canvas, \
t_fractol_painter *painter)
{
	set_complex_number(&painter->c, \
		painter->complex_end.real - (canvas->settings.pixel_size * painter->x), \
		painter->complex_end.imaginary + \
			(canvas->settings.pixel_size * painter->y));
}

void	paint_pixel(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	calculate_painter_c(canvas, painter);
	mlx_put_pixel(canvas->image, painter->x, painter->y, \
		distance_to_color(
			fractal(&canvas->z, &painter->c, \
				painter->border_size, canvas->settings.iteration)));
}

void	init_painter(t_fractol_painter *painter, t_fractol_canvas *canvas)
{
	set_complex_number(&painter->complex_end, \
		canvas->complex_start.real + \
		(canvas->settings.pixel_size * canvas->end_x),
		canvas->complex_start.imaginary - \
		(canvas->settings.pixel_size * canvas->end_y));
	painter->c.imaginary = canvas->complex_start.imaginary;
	painter->c.real = canvas->complex_start.real;
	painter->border_size = \
		canvas->settings.pixel_size * canvas->settings.pixel_size * \
		canvas->settings.border_thickness * canvas->settings.border_thickness;
	set_canvas_pixels_empty(canvas);
}
