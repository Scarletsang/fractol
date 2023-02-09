/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:28:11 by htsang            #+#    #+#             */
/*   Updated: 2023/02/10 00:06:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

int	translate_left_or_right(t_fractol_context *program, unsigned int controls)
{
	if (!controls || controls == 0b0011)
	{
		return (0);
	}
	if ((controls & TRANSLATE_LEFT) == TRANSLATE_LEFT)
	{
		copy_pixels_right(program->canvas.image, 20);
		calculate_left_translation(&program->canvas, 20);
	}
	else
	{
		copy_pixels_left(program->canvas.image, 20);
		calculate_right_translation(&program->canvas, 20);
	}
	program->painter_func( \
		&program->canvas, &program->painter, program->fractal);
	return (1);
}

int	translate_up_or_down(t_fractol_context *program, unsigned int controls)
{
	if (!controls || controls == 0b1100)
	{
		return (0);
	}
	if ((controls & TRANSLATE_DOWN) == TRANSLATE_DOWN)
	{
		copy_pixels_up(program->canvas.image, 20);
		calculate_down_translation(&program->canvas, 20);
	}
	else
	{
		copy_pixels_down(program->canvas.image, 20);
		calculate_up_translation(&program->canvas, 20);
	}
	program->painter_func( \
		&program->canvas, &program->painter, program->fractal);
	return (1);
}

int	translate(t_fractol_context *program)
{
	int	painted;

	painted = translate_left_or_right(program, program->controls & 0b0011);
	painted += translate_up_or_down(program, program->controls & 0b1100);
	return (painted);
}