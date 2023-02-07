/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/07 22:11:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>
#include <unistd.h>

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

int	move_painter(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	int result;

	if (tracer->direction == TRACER_SOUTH)
	{
		result = (painter->y + 1 < canvas->end_y);
		painter->y += result;
	}
	else if (tracer->direction == TRACER_WEST)
	{
		result = (painter->x > (canvas->start_x + 1));
		painter->x -= result;
	}
	else if (tracer->direction == TRACER_NORTH)
	{
		result = (painter->y > (canvas->start_y + 1));
		painter->y -= result;
	}
	else
	{
		result = (painter->x + 1 < canvas->end_x);
		painter->x += result;
	}
	return (result);
}

static int	trace_fractal(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer, t_fractol_func fractal)
{
	uint32_t	*current;

	current = get_pixel(canvas, painter->x, painter->y);
	while (tracer->step < 7)
	{
		if (pixel_is_empty(current))
			paint_pixel(canvas, painter, fractal);
		if (pixel_is_inset(current))
		{
			// printf("direction: %d\tx: %d\ty: %d\tstart_y: %d\n", tracer->direction, painter->x, painter->y, canvas->start_y);
			if ((tracer->x == painter->x) && (tracer->y == painter->y) \
			&& (tracer->direction == TRACER_NORTH))
				return (EXIT_SUCCESS);
			// if (tracer->direction == TRACER_NORTH)
			// 	tracer->direction = TRACER_WEST;
			// else
			// 	tracer->direction--;
			return (EXIT_FAILURE);
		}
		tracer->step++;
		if ((tracer->step % 2) != 0)
		{
			if (tracer->direction == TRACER_WEST)
				tracer->direction = TRACER_NORTH;
			else
				tracer->direction++;
		}
		if (!move_painter(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}

int	moore_neighbours(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer, t_fractol_func fractal)
{
	if (tracer->direction == TRACER_NORTH)
	{
		if (prepare_trace_north(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	else if (tracer->direction == TRACER_EAST)
	{
		if (prepare_trace_east(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	else if (tracer->direction == TRACER_WEST)
	{
		if (prepare_trace_west(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	else
	{
		if (prepare_trace_south(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	return (trace_fractal(canvas, painter, tracer, fractal));
}

void	border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_tracer	tracer;

	tracer.direction = TRACER_NORTH;
	tracer.x = painter->x;
	tracer.y = painter->y;
	printf("bdirection: %d\tx: %d\ty: %d\tstart_y: %d\n", tracer.direction, painter->x, painter->y, canvas->start_y);
	int i = 0;
	while (i < 500)
	{
		if (!moore_neighbours(canvas, painter, &tracer, fractal))
			break ;
		printf("adirection: %d\tx: %d\ty: %d\tstart_y: %d\n", tracer.direction, painter->x, painter->y, canvas->start_y);
		i++;
	}
	printf("edirection: %d\tx: %d\ty: %d\tstart_y: %d\n", tracer.direction, painter->x, painter->y, canvas->start_y);
	painter->x = tracer.x;
	painter->y = tracer.y;
}

int	debug_paint_fractal(t_fractol_canvas *canvas, uint32_t x, uint32_t y, t_fractol_func fractal)
{
	t_fractol_painter	painter;
	uint32_t			*current;

	painter.border_size = \
		canvas->settings.pixel_size * canvas->settings.pixel_size * \
		canvas->settings.border_thickness * canvas->settings.border_thickness;
	painter.x = x;
	painter.y = y;
	current = get_pixel(canvas, painter.x, painter.y);
	paint_pixel(canvas, &painter, fractal);
	printf("before: 0x%08x\t", *current);
	printf("after: 0x%08x\t", *current);
	printf("color: 0x%08x\t", INSET_COLOR);
	printf("re: %d\n", pixel_is_inset(current));
	fflush(stdout);
	// border_trace(canvas, &painter, fractal);
	// if (pixel_is_empty(current))
	// {
	// 	if (pixel_is_inset(current))
	// 		border_trace(canvas, &painter, fractal);
	// }
	return (0);
}

int	paint_fractal(t_fractol_canvas *canvas, t_fractol_func fractal)
{
	t_fractol_painter	painter;
	uint32_t			*current;

	init_painter(canvas, &painter);
	painter.x = 0;
	painter.y = 0;
	border_trace(canvas, &painter, fractal);
	// painter.y = canvas->start_y;
	// while (painter.y < canvas->end_y)
	// {
	// 	painter.x = canvas->start_x;
	// 	while (painter.x < canvas->end_x)
	// 	{
	// 		current = get_pixel(canvas, painter.x, painter.y);
	// 		if (pixel_is_empty(current))
	// 		{
	// 			paint_pixel(canvas, &painter, fractal);
	// 			if (pixel_is_inset(current))
	// 				border_trace(canvas, &painter, fractal);
	// 		}
	// 		else if (pixel_is_inset(current))
	// 		{
	// 			paint_inset_pixels(canvas, &painter, fractal);
	// 			break ;
	// 		}
	// 		painter.x++;
	// 	}
	// 	painter.y++;
	// }
	return (0);
}
