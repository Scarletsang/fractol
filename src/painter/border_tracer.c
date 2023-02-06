/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 06:37:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

static void	paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	painter->x++;
	while ((painter->x < canvas->end_x) && \
		pixel_is_empty(get_pixel(canvas, painter->x, painter->y)))
	{
		paint_pixel(canvas, painter, fractal);
		painter->x++;
	}
}

static int	moore_neighbors(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_tracer *tracer, t_fractol_func fractal)
{
	uint32_t	*current;
	uint32_t	step;

	step = 1;
	while (step < 9)
	{
		current = get_pixel(canvas, painter->x, painter->y);
		if (pixel_is_empty(current))
		{
			paint_pixel(canvas, painter, fractal);
		}
		if (pixel_is_inset(current))
		{
			flip_direction(tracer, step);
			while (!move_painter(canvas, painter, tracer))
			{
				flip_direction(tracer, step);
			}
			return (0);
		}
		step++;
		turn_direction_clockwise(tracer, step);
		move_painter(canvas, painter, tracer);
		printf("direction: %d\tx: %d\ty: %d\tstart_y: %d\n", tracer->direction, painter->x, painter->y, canvas->start_y);
	}
	return (1);
}

static void	border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_tracer	tracer;

	tracer.direction = TRACER_LEFT;
	tracer.x = painter->x;
	tracer.y = painter->y;
	move_painter(canvas, painter, &tracer);
	while ((tracer.x != painter->x) || (tracer.y != painter->y) \
		|| (tracer.direction != TRACER_LEFT))
	{
		if (moore_neighbors(canvas, painter, &tracer, fractal))
			break ;
	}
	painter->x = tracer.x + 1;
	painter->y = tracer.y;
}

int	paint_fractal(t_fractol_canvas *canvas, t_fractol_func fractal)
{
	t_fractol_painter	painter;
	uint32_t			*current;

	init_painter(canvas, &painter);
	painter.y = canvas->start_y;
	while (painter.y < canvas->end_y)
	{
		painter.x = canvas->start_x;
		while (painter.x < canvas->end_x)
		{
			current = get_pixel(canvas, painter.x, painter.y);
			if (pixel_is_empty(current))
			 	paint_pixel(canvas, &painter, fractal);
			if (pixel_is_inset(current) && \
				!peek_pixel_x_is_inset(canvas, painter.x - 1, painter.y))
			{
				border_trace(canvas, &painter, fractal);
			}
			else if (!pixel_is_inset(current) && \
				peek_pixel_x_is_inset(canvas, painter.x + 1, painter.y))
			{
				paint_inset_pixels(canvas, &painter, fractal);
				break ;
			}
			painter.x++;
		}
		painter.y++;
	}
	return (0);
}
