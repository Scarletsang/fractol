/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:06:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 16:22:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/controls/animation.h"

void	init_animation(t_fractol_canvas *canvas, t_fractol_painter *painter)
{
	init_canvas_before_paint(canvas);
	clear_image(canvas);
	painter->y = canvas->start_y;
	painter->x = canvas->start_x;
	painter->animation.border_trace_started = 0;
}

static void	animate_fractal_internal(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	t_fractol_distance	*current;

	current = get_distance_map_point(canvas, painter->x, painter->y);
	if (point_is_empty(current))
	{
		paint_pixel(canvas, painter, fractal);
		if (point_is_inset(current))
			init_animate_border_trace(canvas, painter, fractal);
	}
	else if (point_is_inset(current))
		paint_inset_pixels(canvas, painter);
}

int	animate_fractal(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	uint32_t	i;

	i = 0;
	while (i++ < painter->animation.speed)
	{
		if (painter->animation.border_trace_started)
		{
			animate_border_trace(canvas, painter, fractal, &i);
			continue ;
		}
		if (painter->y >= canvas->end_y)
			return (EXIT_FAILURE);
		if (painter->x < canvas->end_x)
		{
			animate_fractal_internal(canvas, painter, fractal);
			painter->x++;
			continue ;
		}
		painter->x = canvas->start_x;
		painter->y++;
	}
	return (EXIT_SUCCESS);
}

int	init_animate_fractal(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	default_canvas_bounds(canvas);
	init_animation(canvas, painter);
	return (animate_fractal(canvas, painter, fractal));
}
