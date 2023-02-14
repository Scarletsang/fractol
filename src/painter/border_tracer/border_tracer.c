/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:53:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/painter/border_tracer.h"

static void	paint_pixel_from_tracer(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_distance	*distance_point;

	calculate_distance_estimator_c(canvas, painter, painter->tracer.x, \
		painter->tracer.y);
	distance_point = get_distance_map_point(canvas, painter->tracer.x, \
		painter->tracer.y);
	fractal(distance_point, &canvas->estimator);
	mlx_put_pixel(canvas->image, painter->tracer.x, painter->tracer.y, \
		distance_to_color(distance_point, &canvas->base_color));
}

void	almondbread_trace(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	t_fractol_tracer	*tracer;
	t_fractol_distance	*current;
	int					i;

	tracer = &painter->tracer;
	turn_tracer_anticlockwise(tracer);
	i = 0;
	while (i++ < 3)
	{
		if (move_painter(canvas, tracer))
		{
			current = get_distance_map_point(canvas, tracer->x, tracer->y);
			if (point_is_empty(current))
				paint_pixel_from_tracer(canvas, painter, fractal);
			if (point_is_inset(current))
				return ;
			move_painter_backwards(tracer);
		}
		turn_tracer_clockwise(tracer);
	}
	if (!move_painter(canvas, tracer))
		flip_tracer_direction(tracer);
	else if (!point_is_inset(get_pixel(canvas, tracer->x, tracer->y)))
		move_painter_backwards(tracer);
}

void	animate_border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal, uint32_t *iteration)
{
	while (++*iteration < painter->animation.speed)
	{
		almondbread_trace(canvas, painter, fractal);
		if ((painter->tracer.x == painter->tracer.start_x) && \
			(painter->tracer.y == painter->tracer.start_y) && \
			(painter->tracer.direction == painter->tracer.start_direction))
		{
			painter->animation.border_trace_started = 0;
			return ;
		}
	}
}

void	init_animate_border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	painter->animation.border_trace_started = 1;
	painter->tracer.x = painter->x;
	painter->tracer.y = painter->y;
	painter->tracer.direction = TRACER_EAST;
	almondbread_trace(canvas, painter, fractal);
	painter->tracer.start_x = painter->tracer.x;
	painter->tracer.start_y = painter->tracer.y;
	painter->tracer.start_direction = painter->tracer.direction;
}

void	border_trace(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	painter->tracer.x = painter->x;
	painter->tracer.y = painter->y;
	painter->tracer.direction = TRACER_EAST;
	almondbread_trace(canvas, painter, fractal);
	painter->tracer.start_x = painter->tracer.x;
	painter->tracer.start_y = painter->tracer.y;
	painter->tracer.start_direction = painter->tracer.direction;
	while (1)
	{
		almondbread_trace(canvas, painter, fractal);
		if ((painter->tracer.x == painter->tracer.start_x) && \
			(painter->tracer.y == painter->tracer.start_y) && \
			(painter->tracer.direction == painter->tracer.start_direction))
			break ;
	}
}
