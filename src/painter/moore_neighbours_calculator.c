/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moore_neighbours_calculator.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:05:20 by htsang            #+#    #+#             */
/*   Updated: 2023/02/07 17:58:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

int	check_east_border(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if ((painter->x + 1) < canvas->end_x)
	{
		painter->x++;
		tracer->direction = TRACER_SOUTH;
		return (1);
	}
	return (0);
}

int	check_west_border(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (painter->x >= (canvas->start_x + 1))
	{
		painter->x--;
		tracer->direction = TRACER_NORTH;
		return (1);
	}
	return (0);
}

int	check_north_border(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (painter->y >= (canvas->start_y + 1))
	{
		painter->y--;
		tracer->direction = TRACER_EAST;
		return (1);
	}
	return (0);
}

int	check_south_border(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if ((painter->y + 1) < canvas->end_y)
	{
		painter->y++;
		tracer->direction = TRACER_WEST;
		return (1);
	}
	return (0);
}

int	prepare_trace_north(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (check_west_border(canvas, painter, tracer))
	{
		tracer->step = 1;
		if (check_south_border(canvas, painter, tracer))
		{
			tracer->step = 0;
		}
	}
	else if (check_north_border(canvas, painter, tracer))
	{
		tracer->step = 3;
	}
	else if (check_east_border(canvas, painter, tracer))
	{
		tracer->step = 5;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	prepare_trace_east(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (check_north_border(canvas, painter, tracer))
	{
		tracer->step = 1;
		if (check_west_border(canvas, painter, tracer))
		{
			tracer->step = 0;
		}
	}
	else if (check_east_border(canvas, painter, tracer))
	{
		tracer->step = 3;
	}
	else if (check_south_border(canvas, painter, tracer))
	{
		tracer->step = 5;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	prepare_trace_south(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (check_east_border(canvas, painter, tracer))
	{
		tracer->step = 1;
		if (check_north_border(canvas, painter, tracer))
		{
			tracer->step = 0;
		}
	}
	else if (check_south_border(canvas, painter, tracer))
	{
		tracer->step = 3;
	}
	else if (check_west_border(canvas, painter, tracer))
	{
		tracer->step = 5;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	prepare_trace_west(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_tracer *tracer)
{
	if (check_south_border(canvas, painter, tracer))
	{
		tracer->step = 1;
		if (check_east_border(canvas, painter, tracer))
		{
			tracer->step = 0;
		}
	}
	else if (check_west_border(canvas, painter, tracer))
	{
		tracer->step = 3;
	}
	else if (check_north_border(canvas, painter, tracer))
	{
		tracer->step = 5;
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
