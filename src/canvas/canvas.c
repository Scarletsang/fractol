/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 23:21:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/canvas.h"

uint32_t	*get_pixel(t_fractol_canvas *canvas, uint32_t x, uint32_t y)
{
	return ((uint32_t *) canvas->image->pixels + \
		(y * canvas->image->width + x));
}

t_fractol_canvas	*init_canvas(t_fractol_canvas *canvas)
{
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	return (canvas);
}

void	clear_canvas(t_fractol_canvas *canvas)
{
	canvas->estimator.border_size = \
		canvas->pixel_size * canvas->pixel_size * \
		canvas->border_thickness * canvas->border_thickness;
	set_distance_map_empty(canvas);
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