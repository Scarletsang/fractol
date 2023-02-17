/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:07:28 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 14:37:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/canvas.h"

int	point_is_inset(t_fractol_distance *distance_point)
{
	return (distance_point->distance == INSET_VALUE);
}

int	point_is_empty(t_fractol_distance *distance_point)
{
	return (distance_point->distance == EMPTY_VALUE);
}

t_fractol_distance	*get_distance_map_point(t_fractol_canvas *canvas, \
uint32_t x, uint32_t y)
{
	return (canvas->distance_map + (canvas->image->width * y) + x);
}

void	malloc_distance_map(t_fractol_canvas *canvas)
{
	if (canvas->distance_map)
	{
		free(canvas->distance_map);
	}
	canvas->distance_map = malloc(sizeof(t_fractol_distance) * \
		canvas->image->width * canvas->image->height);
}

t_fractol_canvas	*clear_distance_map(t_fractol_canvas *canvas)
{
	uint32_t	x;
	uint32_t	y;

	y = canvas->start_y;
	while (y < canvas->end_y)
	{
		x = canvas->start_x;
		while (x < canvas->end_x)
		{
			get_distance_map_point(canvas, x, y)->distance = EMPTY_VALUE;
			x++;
		}
		y++;
	}
	return (canvas);
}
