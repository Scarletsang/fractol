/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:28:11 by htsang            #+#    #+#             */
/*   Updated: 2023/02/08 23:16:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

int	translate_left_or_right(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal, unsigned int controls)
{
	if (!controls || controls == 0b0011)
	{
		return (0);
	}
	if ((controls & TRANSLATE_LEFT) == TRANSLATE_LEFT)
	{
		copy_pixels_right(canvas->image, 20);
		calculate_left_translation(canvas, 20);
	}
	else
	{
		copy_pixels_left(canvas->image, 20);
		calculate_right_translation(canvas, 20);
	}
	paint_fractal(canvas, painter, fractal);
	return (1);
}

int	translate_up_or_down(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal, unsigned int controls)
{
	if (!controls || controls == 0b1100)
	{
		return (0);
	}
	if ((controls & TRANSLATE_DOWN) == TRANSLATE_DOWN)
	{
		copy_pixels_up(canvas->image, 20);
		calculate_down_translation(canvas, 20);
	}
	else
	{
		copy_pixels_down(canvas->image, 20);
		calculate_up_translation(canvas, 20);
	}
	paint_fractal(canvas, painter, fractal);
	return (1);
}
