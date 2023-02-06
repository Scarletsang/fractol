/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:49:25 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 06:32:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

int	move_painter(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	int	result;

	if (tracer->direction == TRACER_DOWN)
	{
		result =  ((painter->y + 1) < canvas->end_y);
		painter->y += result;
	}
	else if (tracer->direction == TRACER_LEFT)
	{
		result = (painter->x > (canvas->start_x + 1));
		painter->x -= result;
	}
	else if (tracer->direction == TRACER_UP)
	{
		result = painter->y > (canvas->start_y + 1);
		painter->y -= result;
	}
	else
	{
		result = ((painter->x + 1) < canvas->end_x);
		painter->x += result;
	}
	return (result);
}

void	flip_direction(t_fractol_tracer *tracer, uint32_t step)
{
	if (step == 1)
	{
		return ;
	}
	if (tracer->direction == TRACER_UP || tracer->direction == TRACER_RIGHT)
	{
		tracer->direction += 2;
	}
	else
	{
		tracer->direction -= 2;
	}
}

void	turn_direction_clockwise(t_fractol_tracer *tracer, uint32_t step)
{
	if (step == 1 || ((step & 1) == 0))
	{
		if (tracer->direction == TRACER_LEFT)
		{
			tracer->direction = TRACER_UP;
		}
		else
		{
			tracer->direction++;
		}
	}
}
