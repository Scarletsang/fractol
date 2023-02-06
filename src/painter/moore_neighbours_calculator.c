/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moore_neighbours_calculator.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:05:20 by htsang            #+#    #+#             */
/*   Updated: 2023/02/06 17:37:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

int	prepare_trace_up(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if ((painter->x >= (canvas->start_x + 1)) && \
		(painter->x >= (canvas->start_x + 1)))
	{
		painter->x--;
		painter->y++;
		tracer->step = 0;
	}
	else if (painter->y >= (canvas->start_y + 1))
	{
		painter->y--;
		tracer->direction = TRACER_RIGHT;
		tracer->step = 3;
	}
	else if ((painter->x + 1) < canvas->end_x)
	{
		painter->x++;
		tracer->direction = TRACER_DOWN;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	prepare_trace_right(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if ((painter->y >= (canvas->start_y + 1)) && \
		painter->x >= (canvas->start_x + 1))
	{
		painter->x--;
		painter->y--;
		tracer->step = 0;
	}
	else if ((painter->x + 1) < canvas->end_x)
	{
		painter->x++;
		tracer->direction = TRACER_DOWN;
		tracer->step = 3;
	}
	else if ((painter->y + 1) < canvas->end_y)
	{
		painter->x++;
		tracer->direction = TRACER_LEFT;
		tracer->step = 5;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	prepare_trace_down(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (((painter->x + 1) < canvas->end_x) && \
		(painter->y >= (canvas->start_y + 1)))
	{
		painter->x++;
		painter->y--;
		tracer->step = 0;
	}
	else if ((painter->y + 1) < canvas->end_y)
	{
		painter->y++;
		tracer->direction = TRACER_LEFT;
		tracer->step = 3;
	}
	else if (painter->x >= (canvas->start_x + 1))
	{
		painter->x--;
		tracer->direction = TRACER_UP;
		tracer->step = 5;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	prepare_trace_left(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (((painter->y + 1) < canvas->end_y) && \
		((painter->x + 1) < canvas->end_x))
	{
		painter->x++;
		painter->y++;
		tracer->step = 0;
	}
	else if (painter->x >= (canvas->start_x + 1))
	{
		painter->x--;
		tracer->direction = TRACER_UP;
		tracer->step = 3;
	}
	else if (painter->y >= (canvas->start_y + 1))
	{
		painter->y--;
		tracer->direction = TRACER_RIGHT;
		tracer->step = 5;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
