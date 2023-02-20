/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:31:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 16:33:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/painter.h"

void	paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter)
{
	t_fractol_distance	*current;

	while (++painter->x < canvas->end_x)
	{
		current = get_distance_map_point(canvas, painter->x, painter->y);
		if (point_is_empty(current))
		{
			current->distance = INSET_VALUE;
		}
		else if (!point_is_inset(current))
		{
			return ;
		}
	}
}

int	paint_fractal(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	t_fractol_distance	*current;

	init_canvas_before_paint(canvas);
	painter->y = canvas->start_y;
	while (painter->y < canvas->end_y)
	{
		painter->x = canvas->start_x;
		while (painter->x < canvas->end_x)
		{
			current = get_distance_map_point(canvas, painter->x, painter->y);
			if (point_is_empty(current))
			{
				paint_pixel(canvas, painter, fractal);
				if (point_is_inset(current))
					border_trace(canvas, painter, fractal);
			}
			else if (point_is_inset(current))
				paint_inset_pixels(canvas, painter);
			painter->x++;
		}
		painter->y++;
	}
	return (EXIT_SUCCESS);
}
