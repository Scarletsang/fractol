/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:46:35 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 22:55:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/context.h"

void	calculate_zoom(t_fractol_context *program, double ydelta)
{
	double				zoom_percentage;
	t_fractol_complex	mouse;

	convert_cursor_pos_to_complex(program, &mouse);
	zoom_percentage = (fabs(ydelta) / 50) * program->canvas.pixel_size;
	if (ydelta < 0)
		zoom_percentage *= -1;
	program->canvas.pixel_size += zoom_percentage;
	set_complex_number(&program->canvas.viewport, \
		mouse.real - (program->mouse_x * program->canvas.pixel_size), \
		mouse.imaginary + \
			(program->mouse_y * program->canvas.pixel_size));
}

static int	realloc_distance_map(t_fractol_canvas *canvas, \
int32_t width, int32_t height)
{
	t_fractol_distance	*distance_map;
	uint32_t			x;
	uint32_t			y;

	distance_map = malloc(sizeof(t_fractol_distance) * width * height);
	if (!distance_map)
	{
		return (EXIT_FAILURE);
	}
	y = canvas->start_y;
	while (y < canvas->end_y)
	{
		x = canvas->start_x;
		while (x < canvas->end_x)
		{
			*(distance_map + (width * y) + x) = \
				*get_distance_map_point(canvas, x, y);
			x++;
		}
		y++;
	}
	free(canvas->distance_map);
	canvas->distance_map = distance_map;
	return (EXIT_SUCCESS);
}

int	calculate_canvas_resize(t_fractol_canvas *canvas, \
int32_t width, int32_t height)
{
	int32_t	canvas_width;
	int32_t	canvas_height;

	canvas_width = canvas->image->width;
	canvas_height = canvas->image->height;
	if (width < canvas_width)
		canvas_width = width;
	if (height < canvas_height)
		canvas_height = height;
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, canvas_width, canvas_height);
	if (realloc_distance_map(canvas, width, height))
	{
		return (EXIT_FAILURE);
	}
	set_canvas_end(canvas, width, height);
	mlx_resize_image(canvas->image, width, height);
	return (EXIT_SUCCESS);
}

void	shift_color(t_fractol_context *program)
{
	program->animation_time += program->mlx->delta_time;
	set_potential_factor(&program->canvas.color_controls, \
		program->animation_time);
}
