/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 19:39:09 by htsang           ###   ########.fr       */
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

void	paint_on_distance_map(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	calculate_distance_estimator_c(canvas, painter->x, painter->y);
	fractal(get_distance_map_point(canvas, painter->x, painter->y), \
		&canvas->estimator);
}

void	paint_pixel(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_distance	*distance_point;

	calculate_distance_estimator_c(canvas, painter->x, painter->y);
	distance_point = get_distance_map_point(canvas, painter->x, painter->y);
	fractal(distance_point, &canvas->estimator);
	mlx_put_pixel(canvas->image, painter->x, painter->y, \
		distance_to_color(distance_point, &canvas->color_controls));
}

void	init_painter(t_fractol_canvas *canvas)
{
	canvas->estimator.border_size = \
		canvas->pixel_size * canvas->pixel_size * \
		canvas->border_thickness * canvas->border_thickness;
	set_distance_map_empty(canvas);
}
