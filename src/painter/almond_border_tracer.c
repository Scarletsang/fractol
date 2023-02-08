/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almond_border_tracer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/08 16:00:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

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
	if (move_painter(canvas, painter, tracer))
	{
		if (pixel_is_empty(get_pixel(canvas, painter->x, painter->y)))
			paint_pixel(canvas, painter, fractal);
		return ;
	}
	flip_tracer_direction(tracer);
	return ;
}

void	border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_tracer			tracer;
	int	x = painter->x, y = painter->y;

	tracer.direction = TRACER_EAST;
	tracer.step = 1;
	almondbread_trace(canvas, painter, &tracer, fractal);
	tracer.x = painter->x;
	tracer.y = painter->y;
	tracer.start_direction = tracer.direction;
	while (1)
	{
		almondbread_trace(canvas, painter, &tracer, fractal);
		if ((painter->x == tracer.x) && (painter->y == tracer.y) && (tracer.direction == tracer.start_direction))
			break ;
		tracer.step++;
		if (tracer.step == 50000)
		{
			printf("edirection: %d\tx: %d\ty: %d\tori_x: %d\tori_y: %d\n", tracer.start_direction, tracer.x, tracer.y, x, y);
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
	painter->x = x;
	painter->y = y;
}

static void	paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	uint32_t	*current;
	
	while (++painter->x < canvas->end_x)
	{
		current = get_pixel(canvas, painter->x, painter->y);
		if (pixel_is_empty(current))
		{
			mlx_put_pixel(canvas->image, painter->x, painter->y, 0xff123456);
		}
		else if (!pixel_is_inset(current))
		{
			painter->x++;
			return ;
		}
	}
}

int	paint_fractal(t_fractol_canvas *canvas, t_fractol_func fractal)
{
	t_fractol_painter	painter;
	uint32_t			*current;

	init_painter(canvas, &painter);
	painter.y = 227;
	painter.x = 452;
	paint_pixel(canvas, &painter, fractal);
	border_trace(canvas, &painter, fractal);
	paint_inset_pixels(canvas, &painter, fractal);
	return (0);
}

// int	paint_fractal(t_fractol_canvas *canvas, t_fractol_func fractal)
// {
// 	t_fractol_painter	painter;
// 	uint32_t			*current;

// 	init_painter(canvas, &painter);
// 	painter.y = canvas->start_y;
// 	while (painter.y < canvas->end_y)
// 	{
// 		painter.x = canvas->start_x;
// 		while (painter.x < canvas->end_x)
// 		{
// 			current = get_pixel(canvas, painter.x, painter.y);
// 			if (pixel_is_empty(current))
// 			{
// 				paint_pixel(canvas, &painter, fractal);
// 				if (pixel_is_inset(current))
// 				{
// 					border_trace(canvas, &painter, fractal);
// 					paint_inset_pixels(canvas, &painter, fractal);
// 				}
// 			}
// 			else if (pixel_is_inset(current))
// 			{
// 				paint_inset_pixels(canvas, &painter, fractal);
// 			}
// 			painter.x++;
// 		}
// 		painter.y++;
// 	}
// 	return (0);
// }
