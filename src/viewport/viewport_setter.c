/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_setter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 14:08:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

t_fractol_context	*set_viewport_boundaries( t_fractol_context *program, \
double center_real, double center_imaginary)
{
	program->viewport.math.real_min = center_real - \
		(program->viewport.painter.pixel_size * program->canvas->width / 2);
	program->viewport.math.imaginary_max = center_imaginary + \
		(program->viewport.painter.pixel_size * program->canvas->height / 2);
	return (program);
}

t_fractol_context	*set_painter_pixels(t_fractol_context *program, \
uint32_t offset)
{
	program->viewport.painter.pixels = \
		(uint32_t *)(program->canvas->pixels + offset);
	return (program);
}

t_fractol_context	*resize_viewport(t_fractol_context *program, \
int32_t width, int32_t height)
{
	mlx_resize_image(program->canvas, width, height);
	program->viewport.painter.height = height;
	program->viewport.painter.width = width;
	return (set_painter_pixels(program, 0));
}
