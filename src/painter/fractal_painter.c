/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:31:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 20:02:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/painter.h"
#include <time.h>
#include <stdio.h>

void	paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter)
{
	t_fractol_distance	*current;

	while (++painter->x < canvas->end_x)
	{
		current = get_pixel(canvas, painter->x, painter->y);
		if (pixel_is_empty(current))
		{
			mlx_put_pixel(canvas->image, painter->x, painter->y, INSET_COLOR);
		}
		else if (!pixel_is_inset(current))
		{
			return ;
		}
	}
}

int	paint_fractal(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	t_fractol_distance	*current;
	time_t				start = clock();

	init_painter(canvas);
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
	printf("%f\n", ((double) clock() - start) / CLOCKS_PER_SEC);
	return (EXIT_SUCCESS);
}
