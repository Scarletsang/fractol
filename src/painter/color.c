/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:06:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/15 22:37:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/painter.h"

uint32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	calculate_potential(t_fractol_distance *distance_point)
{
	distance_point->potential *= sqrt(sqrt(distance_point->distance));
}

void	divide_potential_by_factor(t_fractol_distance *distance_point, \
int32_t potential_factor)
{
	distance_point->potential /= (potential_factor + 0.1);
}

uint32_t	calculate_color(t_fractol_distance *distance_point, \
t_fractol_color_controls *color_controls)
{
	return (get_rgba(\
		((1 - cos(color_controls->r_factor * distance_point->potential)) \
		/ 2)  * color_controls->r, \
		((1 - cos(color_controls->g_factor * distance_point->potential)) \
		/ 2) * color_controls->g, \
		((1 - cos(color_controls->b_factor * distance_point->potential)) \
		/ 2) * color_controls->b, 0xFF));
}

uint32_t	distance_to_color(t_fractol_distance *distance_point, \
t_fractol_color_controls *color_controls)
{
	if (distance_point->distance == BORDER_VALUE)
	{
		return (BOUNDARY_COLOR);
	}
	if (distance_point->distance == INSET_VALUE)
	{
		return (INSET_COLOR);
	}
	calculate_potential(distance_point);
	divide_potential_by_factor(distance_point, color_controls->potential_factor);
	return (calculate_color(distance_point, color_controls));
}
