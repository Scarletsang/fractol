/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:20:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/08 23:40:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_border_tracer.h"

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

void	move_painter_backwards(t_fractol_painter *painter)
{
	if (painter->tracer.direction == TRACER_SOUTH)
	{
		painter->y -= 1;
	}
	else if (painter->tracer.direction == TRACER_WEST)
	{
		painter->x += 1;
	}
	else if (painter->tracer.direction == TRACER_NORTH)
	{
		painter->y += 1;
	}
	else
	{
		painter->x -= 1;
	}
}

int	move_painter(t_fractol_canvas *canvas, t_fractol_painter *painter)
{
	int	result;

	if (painter->tracer.direction == TRACER_SOUTH)
	{
		result = ((painter->y + 1) < canvas->end_y);
		painter->y += result;
	}
	else if (painter->tracer.direction == TRACER_WEST)
	{
		result = (painter->x >= (canvas->start_x + 1));
		painter->x -= result;
	}
	else if (painter->tracer.direction == TRACER_NORTH)
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
