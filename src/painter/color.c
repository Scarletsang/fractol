/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:06:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/13 22:10:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

uint32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	distance_to_color(t_fractol_distance *distance, \
t_fractol_base_color *base_color)
{
	double	calculated;

	if (distance->distance == BORDER_VALUE)
	{
		return (BOUNDARY_COLOR);
	}
	if (distance->distance == INSET_VALUE)
	{
		return (INSET_COLOR);
	}
	calculated = 1 / log(distance * base_color->factor);
	return (\
		get_rgba(base_color->r * calculated, base_color->g * calculated, \
			base_color->b, 0xff));
}
