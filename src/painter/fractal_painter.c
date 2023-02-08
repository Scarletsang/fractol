/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:31:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/09 00:00:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

static void	paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter)
{
	uint32_t	*current;

	while (++painter->x < canvas->end_x)
	{
		current = get_pixel(canvas, painter->x, painter->y);
		if (pixel_is_empty(current))
		{
			mlx_put_pixel(canvas->image, painter->x, painter->y, INSET_COLOR);
		}
		else if (!pixel_is_inset(current))
		{
			return ;
		}
	}
}

int	paint_fractal_one_frame(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal)
{
	uint32_t	*current;
	uint32_t	i;

	i = 0;
	while ((painter->y < canvas->end_y) && (i++ < painter->speed))
	{
		if (painter->x < canvas->end_x)
		{
			current = get_pixel(canvas, painter->x, painter->y);
			if (pixel_is_empty(current))
			{
				paint_pixel(canvas, painter, fractal);
				if (pixel_is_inset(current))
					border_trace(canvas, painter, fractal);
			}
			else if (pixel_is_inset(current))
				paint_inset_pixels(canvas, painter);
			painter->x++;
			continue ;
		}
		painter->x = canvas->start_x;
		painter->y++;
	}
	return (0);
}

int	paint_fractal(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	uint32_t	*current;

	init_painter(canvas, painter);
	painter->y = canvas->start_y;
	while (painter->y < canvas->end_y)
	{
		painter->x = canvas->start_x;
		while (painter->x < canvas->end_x)
		{
			current = get_pixel(canvas, painter->x, painter->y);
			if (pixel_is_empty(current))
			{
				paint_pixel(canvas, painter, fractal);
				if (pixel_is_inset(current))
					border_trace(canvas, painter, fractal);
			}
			else if (pixel_is_inset(current))
				paint_inset_pixels(canvas, painter);
			painter->x++;
		}
		painter->y++;
	}
	return (0);
}
