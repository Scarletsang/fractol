/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:06:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 16:13:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/painter.h"

uint32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	calculate_color(t_fractol_distance *distance_point, \
t_fractol_color_controls *color_controls)
{
	double potential;

	potential = distance_point->potential / \
		(color_controls->potential_factor + 0.1);
	return (get_rgba(\
		((1 - cos(color_controls->r_factor * potential)) \
		/ 2)  * color_controls->r, \
		((1 - cos(color_controls->g_factor * potential)) \
		/ 2) * color_controls->g, \
		((1 - cos(color_controls->b_factor * potential)) \
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
	return (calculate_color(distance_point, color_controls));
}
