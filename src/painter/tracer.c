/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:49:25 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 01:59:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

void	move_painter(t_fractol_canvas *canvas, t_fractol_painter *painter)
{
	if (painter->direction == TRACER_DOWN)
	{
		painter->y += (painter->y + 1 < canvas->end_y);
	}
	else if (painter->direction == TRACER_LEFT)
	{
		painter->x -= (painter->x - 1 > canvas->start_x);
	}
	else if (painter->direction == TRACER_UP)
	{
		painter->y -= (painter->y - 1 > canvas->start_y);
	}
	else
	{
		painter->x += (painter->x + 1 < canvas->end_x);
	}
}

void	flip_tracer(t_fractol_painter *painter)
{
	if (painter->direction == TRACER_UP || painter->direction == TRACER_RIGHT)
	{
		painter->direction += 2;
	}
	else
	{
		painter->direction -= 2;
	}
}

void	turn_tracer_clockwise(t_fractol_painter *painter, int32_t step)
{
	if (step == 1 || ((step & 1) == 0))
	{
		if (painter->direction == TRACER_LEFT)
		{
			painter->direction = TRACER_UP;
		}
		else
		{
			painter->direction++;
		}
	}
}
