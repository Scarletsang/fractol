/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/02 21:33:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_canvas.h"

t_fractol_canvas	*set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y)
{
	canvas->end_x = end_x;
	canvas->end_y = end_y;
	return (canvas);
}

t_fractol_canvas	*set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y)
{
	canvas->start_x = start_x;
	canvas->start_y = start_y;
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

t_fractol_canvas	*init_canvas(t_fractol_canvas *canvas, \
t_fractol_complex *viewport)
{
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	set_canvas_complex_start(canvas, viewport, 0, 0);
	return (canvas);
}
