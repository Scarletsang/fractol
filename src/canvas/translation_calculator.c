/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_calculator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:10:43 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 01:06:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

t_fractol_canvas	*calculate_left_translation(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t delta)
{
	move_viewport_real(canvas, viewport, delta, -1);
	set_canvas_complex_start(canvas, viewport, 0, 0);
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, delta, canvas->image->height);
	return (canvas);
}

t_fractol_canvas	*calculate_right_translation(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t delta)
{
	set_canvas_complex_start(canvas, viewport, \
		canvas->image->width * canvas->settings.pixel_size, 0);
	move_viewport_real(canvas, viewport, delta, 1);
	set_canvas_start(canvas, canvas->image->width - delta, 0);
	set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	return (canvas);
}

t_fractol_canvas	*calculate_down_translation(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t delta)
{
	set_canvas_complex_start(canvas, viewport, 0, \
		canvas->image->height * canvas->settings.pixel_size);
	move_viewport_imaginary(canvas, viewport, delta, -1);
	set_canvas_start(canvas, 0, canvas->image->height - delta);
	set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	return (canvas);
}

t_fractol_canvas	*calculate_up_translation(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t delta)
{
	move_viewport_imaginary(canvas, viewport, delta, 1);
	set_canvas_complex_start(canvas, viewport, 0, 0);
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, canvas->image->width, delta);
	return (canvas);
}

t_fractol_canvas	*resize_canvas(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, int32_t width, int32_t height)
{
	mlx_resize_image(canvas->image, width, height);
	set_canvas_complex_start(canvas, viewport, 0, 0);
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, width, height);
	return (canvas);
}
