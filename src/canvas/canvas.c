/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/01/31 23:44:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_canvas.h"

t_fractol_canvas	*set_canvas_dimension(t_fractol_canvas *canvas, \
uint32_t width, uint32_t height)
{
	canvas->width = width;
	canvas->height = height;
	return (canvas);
}

t_fractol_canvas	*set_canvas_offsets(t_fractol_canvas *canvas, \
uint32_t horizontal, uint32_t vertical)
{
	canvas->horizontal_offset = horizontal;
	canvas->vertical_offset = vertical;
	return (canvas);
}

t_fractol_canvas	*set_canvas_vertical_offset(t_fractol_canvas *canvas, \
uint32_t offset)
{
	canvas->vertical_offset = offset;
	return (canvas);
}

t_fractol_canvas	*set_canvas_complex_start(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, double real_offset, double imaginary_offset)
{
	canvas->complex_start.real = \
		viewport->real + real_offset;
	canvas->complex_start.imaginary = \
		viewport->imaginary - imaginary_offset;
	return (canvas);
}

t_fractol_canvas	*set_canvas_settings(t_fractol_canvas *canvas, \
uint32_t iteration, double pixel_size, double border_thickness)
{
	canvas->settings.iteration = iteration;
	canvas->settings.pixel_size = pixel_size;
	canvas->settings.border_thickness = border_thickness;
	return (canvas);
}
