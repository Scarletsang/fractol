/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_setter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 01:38:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

t_fractol_viewport	*set_viewport_boundaries( t_fractol_viewport *viewport, \
double center_real, double center_imaginary)
{
	viewport->math.real_min = center_real - \
		(viewport->painter.pixel_size * viewport->canvas->width / 2);
	viewport->math.imaginary_max = center_imaginary + \
		(viewport->painter.pixel_size * viewport->canvas->height / 2);
	return (viewport);
}

t_fractol_viewport	*set_painter_pixels(t_fractol_viewport *viewport, \
uint32_t offset)
{
	viewport->painter.pixels = \
		(uint32_t *)(viewport->canvas->pixels + offset);
	return (viewport);
}
