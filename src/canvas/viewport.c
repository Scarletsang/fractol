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

void	move_viewport_real(t_fractol_canvas *canvas, \
uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		canvas->viewport.real -= \
			canvas->settings.pixel_size * pixel_amount;
	}
	else
	{
		canvas->viewport.real += \
			canvas->settings.pixel_size * pixel_amount;
	}
}

void	move_viewport_imaginary(t_fractol_canvas *canvas, \
uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		canvas->viewport.imaginary -= \
			canvas->settings.pixel_size * pixel_amount;
	}
	else
	{
		canvas->viewport.imaginary += \
			canvas->settings.pixel_size * pixel_amount;
	}
}
