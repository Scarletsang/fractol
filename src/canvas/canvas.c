/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 14:47:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/canvas.h"

void	set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y)
{
	canvas->end_x = end_x;
	canvas->end_y = end_y;
}

void	set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y)
{
	canvas->start_x = start_x;
	canvas->start_y = start_y;
}

void	default_canvas_bounds(t_fractol_canvas *canvas)
{
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, canvas->image->width, canvas->image->height);
}

void	clear_image(t_fractol_canvas *canvas)
{
	uint32_t	x;
	uint32_t	y;

	y = canvas->start_y;
	while (y < canvas->end_y)
	{
		x = canvas->start_x;
		while (x < canvas->end_x)
		{
			mlx_put_pixel(canvas->image, x, y, 0);
			x++;
		}
		y++;
	}
}

void	init_canvas_before_paint(t_fractol_canvas *canvas)
{
	canvas->estimator.border_size = \
		canvas->pixel_size * canvas->pixel_size * \
		canvas->border_thickness * canvas->border_thickness;
	clear_distance_map(canvas);
}
