/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 03:54:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

void	calculate_painter_c(t_fractol_canvas *canvas, \
t_fractol_painter *painter)
{
	set_complex_number(&painter->c, \
		canvas->viewport.real + \
			(canvas->settings.pixel_size * painter->x), \
		canvas->viewport.imaginary - \
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

void	init_painter(t_fractol_canvas *canvas, t_fractol_painter *painter)
{
	painter->border_size = \
		canvas->settings.pixel_size * canvas->settings.pixel_size * \
		canvas->settings.border_thickness * canvas->settings.border_thickness;
	set_canvas_pixels_empty(canvas);
}
