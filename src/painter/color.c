/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:06:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 02:11:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

uint32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	distance_to_color(double value)
{
	if (value == BORDER_VALUE)
	{
		return (BOUNDARY_COLOR);
	}
	if (value == INSET_VALUE)
	{
		return (INSET_COLOR);
	}
	return (get_rgba(255 * value, 13, 152, 0xff));
}
