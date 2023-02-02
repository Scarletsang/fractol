/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:57:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/02 21:40:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

void	calculate_painter_c(t_fractol_canvas *canvas, t_fractol_painter *painter)
{
	set_complex_number(&painter->c, \
		painter->complex_end.real + (canvas->settings.pixel_size * painter->x), \
		painter->complex_end.imaginary - \
			(canvas->settings.pixel_size * painter->y));
}

void	paint_pixel(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	calculate_painter_c(canvas, painter);
	mlx_put_pixel(&canvas->image, painter->x, painter->y, \
		distance_to_color(
			fractal(&canvas->z, &painter->c, \
				painter->border_size, canvas->settings.iteration)));
}

int32_t	*safe_get_pixel_horizontal(t_fractol_canvas *canvas, int32_t x, int32_t y)
{
	if ((x > canvas->end_x) || x < canvas->start_x)
	{
		return (NULL);
	}
	return (&canvas->image->pixels[(y * canvas->image->width + x) * \
		sizeof(int32_t)]);
}

int32_t	*safe_get_pixel_vertical(t_fractol_canvas *canvas, int32_t x, int32_t y)
{
	if ((y > canvas->end_y) || y < canvas->start_y)
	{
		return (NULL);
	}
	return (&canvas->image->pixels[(y * canvas->image->width + x) * \
		sizeof(int32_t)]);
}

int32_t	*get_pixel(t_fractol_canvas *canvas, int32_t x, int32_t y)
{
	return (&canvas->image->pixels[(y * canvas->image->width + x) * \
		sizeof(int32_t)]);
}

int32_t	*moore_neighbors(t_fractol_painter *painter, t_fractol_func fractal)
{
	
}

void	border_trace(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	painter->tracer
}

void	paint_inset_pixels(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal)
{
	while (pixel_is_empty(safe_get_pixel(canvas, painter->x, painter->y)))
	{
		paint_pixel(canvas, &painter, fractal);
		painter->x++;
	}
}

int	border_trace_fractal(t_fractol_canvas *canvas, t_fractol_func fractal)
{
	t_fractol_painter	painter;
	int32_t				*current;

	init_painter(&painter, canvas);
	painter.y = canvas->start_y;
	while (painter.y <= canvas->end_y)
	{
		painter.x = canvas->start_x;
		while (painter.x <= canvas->end_x)
		{
			current = get_pixel(canvas, painter.x, painter.y);
			if (pixel_is_empty(*current))
				paint_pixel(canvas, &painter, fractal);
			if (pixel_is_inset(*current) && !pixel_is_inset( \
				safe_get_pixel_horizontal(canvas, painter.x - 1, painter.y)))
				border_trace(canvas, &painter, fractal);
			else if (pixel_is_inset(safe_get_pixel_horizontal( \
					canvas, painter.x + 1, painter.y)))
			{
				painter.x++;
				paint_inset_pixels(canvas, &painter, fractal);
			}
			painter.x++;
		}
		painter.y++;
	}
	return (0);
}
