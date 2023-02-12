/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:18:01 by htsang            #+#    #+#             */
/*   Updated: 2023/02/12 23:41:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_canvas.h"

t_fractol_canvas	*set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y)
{
	canvas->end_x = end_x;
	canvas->end_y = end_y;
	return (canvas);
}

t_fractol_canvas	*set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y)
{
	canvas->start_x = start_x;
	canvas->start_y = start_y;
	return (canvas);
}

t_fractol_canvas	*set_canvas_settings(t_fractol_canvas *canvas, \
uint32_t iteration, double border_thickness)
{
	canvas->settings.iteration = iteration;
	canvas->settings.border_thickness = border_thickness;
	return (canvas);
}

t_fractol_canvas	*set_canvas_pixels_empty(t_fractol_canvas *canvas)
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
	return (canvas);
}
