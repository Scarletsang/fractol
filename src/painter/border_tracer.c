/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/06 20:40:44 by htsang           ###   ########.fr       */
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

void	paint_red_pixel(t_fractol_canvas *canvas, t_fractol_painter *painter)
{
	calculate_painter_c(canvas, painter);
	mlx_put_pixel(canvas->image, painter->x, painter->y, 0xffff55ff);
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
				&& (tracer->direction == TRACER_RIGHT))
				return (EXIT_SUCCESS);
			return (EXIT_FAILURE);
		}
		if ((tracer->step == 2) || (tracer->step == 4))
		{
			if (tracer->direction == TRACER_LEFT)
				tracer->direction = TRACER_UP;
			else
				tracer->direction++;
		}
		tracer->step++;
	}
	return (EXIT_FAILURE);
}

int	moore_neighbours(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer, t_fractol_func fractal)
{
	if (tracer->direction == TRACER_UP)
	{
		if (prepare_trace_up(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	else if (tracer->direction == TRACER_RIGHT)
	{
		if (prepare_trace_right(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	else if (tracer->direction == TRACER_LEFT)
	{
		if (prepare_trace_left(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	else
	{
		if (prepare_trace_down(canvas, painter, tracer))
			return (EXIT_FAILURE);
	}
	return (trace_fractal(canvas, painter, tracer, fractal));
}

void	border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_tracer	tracer;

	tracer.direction = TRACER_RIGHT;
	tracer.x = painter->x;
	tracer.y = painter->y;
	printf("bdirection: %d\tx: %d\ty: %d\tstart_y: %d\n", tracer.direction, painter->x, painter->y, canvas->start_y);
	while (1)
	{
		if (!moore_neighbours(canvas, painter, &tracer, fractal))
			break ;
	}
	printf("adirection: %d\tx: %d\ty: %d\tstart_y: %d\n", tracer.direction, painter->x, painter->y, canvas->start_y);
	painter->x = tracer.x;
	painter->y = tracer.y;
}

int	debug_paint_fractal(t_fractol_canvas *canvas, uint32_t x, uint32_t y, t_fractol_func fractal)
{
	t_fractol_painter	painter;
	uint32_t			*current;

	// init_painter(canvas, &painter);
	painter.x = x;
	painter.y = y;
	current = get_pixel(canvas, painter.x, painter.y);
	printf("before: 0x%08x\t", *current);
	paint_pixel(canvas, &painter, fractal);
	printf("after: 0x%08x\t", *current);
	printf("color: 0x%08x\t", INSET_COLOR);
	printf("re: %d\n", pixel_is_inset(current));
	fflush(stdout);
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
	painter.y = canvas->start_y;
	while (painter.y < 1)
	{
		painter.x = canvas->start_x;
		while (painter.x < canvas->end_x)
		{
			current = get_pixel(canvas, painter.x, painter.y);
			if (pixel_is_empty(current))
			{
				paint_pixel(canvas, &painter, fractal);
				if (pixel_is_inset(current))
					border_trace(canvas, &painter, fractal);
			}
			else if (pixel_is_inset(current))
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
