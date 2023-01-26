/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:05:28 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 01:38:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

t_fractol_viewport	*move_real_axis_by(t_fractol_viewport *viewport, \
uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		viewport->math.real_min -= \
			viewport->painter.pixel_size * pixel_amount;
	}
	else
	{
		viewport->math.real_min += \
			viewport->painter.pixel_size * pixel_amount;
	}
	return (viewport);
}

t_fractol_viewport	*move_imaginary_axis_by(t_fractol_viewport *viewport, \
uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		viewport->math.imaginary_max -= \
			viewport->painter.pixel_size * pixel_amount;
	}
	else
	{
		viewport->math.imaginary_max += \
			viewport->painter.pixel_size * pixel_amount;
	}
	return (viewport);
}

t_fractol_viewport	*resize_viewport(t_fractol_viewport *viewport, \
int32_t width, int32_t height)
{
	mlx_resize_image(viewport->canvas, width, height);
	viewport->painter.height = height;
	viewport->painter.width = width;
	return (set_painter_pixels(viewport, 0));
}