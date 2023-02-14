/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:20:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 19:59:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/painter/border_tracer.h"

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

void	move_tracer_backwards(t_fractol_tracer *tracer)
{
	if (tracer->direction == TRACER_SOUTH)
	{
		tracer->y -= 1;
	}
	else if (tracer->direction == TRACER_WEST)
	{
		tracer->x += 1;
	}
	else if (tracer->direction == TRACER_NORTH)
	{
		tracer->y += 1;
	}
	else
	{
		tracer->x -= 1;
	}
}

int	move_tracer(t_fractol_canvas *canvas, t_fractol_tracer *tracer)
{
	int	result;

	if (tracer->direction == TRACER_SOUTH)
	{
		result = ((tracer->y + 1) < canvas->end_y);
		tracer->y += result;
	}
	else if (tracer->direction == TRACER_WEST)
	{
		result = (tracer->x >= (canvas->start_x + 1));
		tracer->x -= result;
	}
	else if (tracer->direction == TRACER_NORTH)
	{
		result = (tracer->y >= (canvas->start_y + 1));
		tracer->y -= result;
	}
	else
	{
		result = ((tracer->x + 1) < canvas->end_x);
		tracer->x += result;
	}
	return (result);
}
