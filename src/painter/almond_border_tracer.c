/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almond_border_tracer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/08 02:15:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>
#include <unistd.h>

void	turn_tracer_clockwise(t_fractol_tracer *tracer)
{
	if (tracer->direction == TRACER_WEST)
	{
		tracer->direction = TRACER_NORTH;
	}
	else
	{
		tracer->direction++;
	}
}

void	turn_tracer_anticlockwise(t_fractol_tracer *tracer)
{
	if (tracer->direction == TRACER_NORTH)
	{
		tracer->direction = TRACER_WEST;
	}
	else
	{
		tracer->direction--;
	}
}

void	flip_tracer_direction(t_fractol_tracer *tracer)
{
	if (tracer->direction >= TRACER_SOUTH)
	{
		tracer->direction -= 2;
	}
	else
	{
		tracer->direction += 2;
	}
}

void	move_painter_backwards(t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (tracer->direction == TRACER_SOUTH)
	{
		painter->y -= 1;
	}
	else if (tracer->direction == TRACER_WEST)
	{
		painter->x += 1;
	}
	else if (tracer->direction == TRACER_NORTH)
	{
		painter->y += 1;
	}
	else
	{
		painter->x -= 1;
	}
}
int	move_painter(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	int result;

	if (tracer->direction == TRACER_SOUTH)
	{
		result = ((painter->y + 1) < canvas->end_y);
		painter->y += result;
	}
	else if (tracer->direction == TRACER_WEST)
	{
		result = (painter->x >= (canvas->start_x + 1));
		painter->x -= result;
	}
	else if (tracer->direction == TRACER_NORTH)
	{
		result = (painter->y >= (canvas->start_y + 1));
		painter->y -= result;
	}
	else
	{
		result = ((painter->x + 1) < canvas->end_x);
		painter->x += result;
	}
	return (result);
}

void	almondbread_trace(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer, t_fractol_func fractal)
{
	uint32_t	*current;
	int			i;

	turn_tracer_anticlockwise(tracer);
	i = 0;
	while (i < 3)
	{
		if (move_painter(canvas, painter, tracer))
		{
			current = get_pixel(canvas, painter->x, painter->y);
			if (pixel_is_empty(current))
				paint_pixel(canvas, painter, fractal);
			if (pixel_is_inset(current))
				return ;
			move_painter_backwards(painter, tracer);
		}
		turn_tracer_clockwise(tracer);
		i++;
	}
	move_painter(canvas, painter, tracer);
	current = get_pixel(canvas, painter->x, painter->y);
	if (pixel_is_empty(current))
		paint_pixel(canvas, painter, fractal);
}

void	border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_tracer			tracer;
	t_fractol_tracer_direction	original_direction;

	tracer.direction = TRACER_EAST;
	tracer.step = 1;
	almondbread_trace(canvas, painter, &tracer, fractal);
	original_direction = tracer.direction;
	tracer.x = painter->x;
	tracer.y = painter->y;
	almondbread_trace(canvas, painter, &tracer, fractal);
	while ((painter->x != tracer.x) || (painter->y != tracer.y) \
	|| (tracer.direction != original_direction))
	{
		almondbread_trace(canvas, painter, &tracer, fractal);
		tracer.step++;
		if (tracer.step == 50000)
		{
			printf("edirection: %d\tx: %d\ty: %d\n", original_direction, tracer.x, tracer.y);
			int i = 0;
			while (i < 10)
			{
				almondbread_trace(canvas, painter, &tracer, fractal);
				printf("sdirection: %d\tx: %d\ty: %d\n", tracer.direction, painter->x, painter->y);
				i++;
			}
			printf("\n");
			break ;
		}
	}
	painter->x = tracer.x;
	painter->y = tracer.y;
}

static void	paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	painter->x++;
	while ((painter->x < canvas->end_x) && \
		pixel_is_empty(get_pixel(canvas, painter->x, painter->y)))
	{
		mlx_put_pixel(canvas->image, painter->x, painter->y, INSET_COLOR);
		painter->x++;
	}
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
			{
				paint_pixel(canvas, &painter, fractal);
				if (pixel_is_inset(current))
				{
					border_trace(canvas, &painter, fractal);
				}
			}
			else if (pixel_is_inset(current))
			{
				paint_inset_pixels(canvas, &painter, fractal);
			}
			painter.x++;
		}
		painter.y++;
	}
	return (0);
}
