/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 03:59:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

static void	paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	while (pixel_is_empty(safe_get_pixel_horizontal(canvas, \
		painter->x, painter->y)))
	{
		paint_pixel(canvas, painter, fractal);
		painter->x++;
	}
}

static int	moore_neighbors(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	uint32_t	*current;
	int32_t	step;

	step = 1;
	while (step < 9)
	{
		move_painter(canvas, painter);
		current = get_pixel(canvas, painter->x, painter->y);
		if (pixel_is_empty(current))
		{
			paint_pixel(canvas, painter, fractal);
		}
		if ((*current & INSET_COLOR) == 0)
		{
			flip_tracer(painter);
			return (0);
		}
		step++;
		turn_tracer_clockwise(painter, step);
	}
	return (1);
}

static void	border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	uint32_t	x;
	uint32_t	y;

	painter->direction = TRACER_DOWN;
	x = painter->x;
	y = painter->y;
	if (moore_neighbors(canvas, painter, fractal))
	{
		painter->x = x + 1;
		painter->y = y;
		return ;
	}
	while ((painter->x != x) || (painter->y != y) \
		|| painter->direction != TRACER_DOWN)
	{
		if (moore_neighbors(canvas, painter, fractal))
			break ;
	}
	painter->x = x + 1;
	painter->y = y;
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
			// if (!(*current & INSET_COLOR) && (*safe_get_pixel_horizontal(\
			// 	canvas, painter.x - 1, painter.y) & INSET_COLOR))
			// 	{
			// 		border_trace(canvas, &painter, fractal);
			// 	}
			// else if (!(*safe_get_pixel_horizontal(canvas, painter.x, \
			// 	painter.y) & INSET_COLOR))
			// {
			// 	painter.x++;
			// 	paint_inset_pixels(canvas, &painter, fractal);
			// 	break ;
			// }
			painter.x++;
		}
		painter.y++;
	}
	return (0);
}
