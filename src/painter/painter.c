/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/02/09 15:50:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

int	pixel_is_inset(uint32_t *pixel)
{
	return (*pixel == (uint32_t)(INSET_COLOR << 24));
}

int	pixel_is_empty(uint32_t *pixel)
{
	return (*pixel == 0);
}

void	calculate_painter_c(t_fractol_canvas *canvas, \
t_fractol_painter *painter, uint32_t x, uint32_t y)
{
	set_complex_number(&painter->c, \
		canvas->viewport.real + \
			(canvas->settings.pixel_size * x), \
		canvas->viewport.imaginary - \
			(canvas->settings.pixel_size * y));
}

void	paint_pixel(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	calculate_painter_c(canvas, painter, painter->x, painter->y);
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
