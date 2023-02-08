/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/08 23:40:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_border_tracer.h"

void	almondbread_trace(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	uint32_t	*current;
	int			i;

	turn_tracer_anticlockwise(&painter->tracer);
	i = 0;
	while (i++ < 3)
	{
		if (move_painter(canvas, painter))
		{
			current = get_pixel(canvas, painter->x, painter->y);
			if (pixel_is_empty(current))
				paint_pixel(canvas, painter, fractal);
			if (pixel_is_inset(current))
				return ;
			move_painter_backwards(painter);
		}
		turn_tracer_clockwise(&painter->tracer);
	}
	if (move_painter(canvas, painter))
	{
		if (pixel_is_inset(get_pixel(canvas, painter->x, painter->y)))
			return ;
		move_painter_backwards(painter);
	}
	flip_tracer_direction(&painter->tracer);
}

void	border_trace(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	uint32_t			original_painter_x;
	uint32_t			original_painter_y;

	original_painter_x = painter->x;
	original_painter_y = painter->y;
	painter->tracer.direction = TRACER_EAST;
	almondbread_trace(canvas, painter, fractal);
	painter->tracer.x = painter->x;
	painter->tracer.y = painter->y;
	painter->tracer.start_direction = painter->tracer.direction;
	while (1)
	{
		almondbread_trace(canvas, painter, fractal);
		if ((painter->x == painter->tracer.x) && \
			(painter->y == painter->tracer.y) && \
			(painter->tracer.direction == painter->tracer.start_direction))
			break ;
	}
	painter->x = original_painter_x;
	painter->y = original_painter_y;
}
