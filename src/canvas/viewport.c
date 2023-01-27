/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:05:28 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 20:29:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_canvas.h"

t_fractol_canvas	*move_viewport_real(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		viewport->real -= \
			canvas->settings.pixel_size * pixel_amount;
	}
	else
	{
		viewport->real += \
			canvas->settings.pixel_size * pixel_amount;
	}
	return (canvas);
}

t_fractol_canvas	*move_viewport_imaginary(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		viewport->imaginary -= \
			canvas->settings.pixel_size * pixel_amount;
	}
	else
	{
		viewport->imaginary += \
			canvas->settings.pixel_size * pixel_amount;
	}
	return (canvas);
}
