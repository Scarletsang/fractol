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

t_fractol_context	*set_viewport(t_fractol_context *program, \
double center_real, double center_imaginary)
{
	program->viewport.real = center_real - \
		(program->canvas.pixel_size * program->image->width / 2);
	program->viewport.imaginary = center_imaginary + \
		(program->canvas.pixel_size * program->image->height / 2);
	return (program);
}

t_fractol_context	*move_viewport_real(t_fractol_context *program, \
uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		program->viewport.real -= \
			program->canvas.pixel_size * pixel_amount;
	}
	else
	{
		program->viewport.real += \
			program->canvas.pixel_size * pixel_amount;
	}
	return (program);
}

t_fractol_context	*move_viewport_imaginary(t_fractol_context *program, \
uint32_t pixel_amount, int direction)
{
	if (direction <= 0)
	{
		program->viewport.imaginary -= \
			program->canvas.pixel_size * pixel_amount;
	}
	else
	{
		program->viewport.imaginary += \
			program->canvas.pixel_size * pixel_amount;
	}
	return (program);
}
