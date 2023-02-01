/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:28:11 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 15:44:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

int	translate_left_or_right(unsigned int controls, \
t_fractol_context *program)
{
	if (!controls || controls == 0b0011)
	{
		return (0);
	}
	if ((controls & TRANSLATE_LEFT) == TRANSLATE_LEFT)
	{
		copy_pixels_right(program->image, 20);
		calculate_left_translation(program, 20);
	}
	else
	{
		copy_pixels_left(program->image, 20);
		calculate_right_translation(program, 20);
	}
	paint_fractal(&program->canvas, program->image, program->fractal);
	return (1);
}

int	translate_up_or_down(unsigned int controls, \
t_fractol_context *program)
{
	if (!controls || controls == 0b1100)
	{
		return (0);
	}
	if ((controls & TRANSLATE_DOWN) == TRANSLATE_DOWN)
	{
		copy_pixels_up(program->image, 20);
		calculate_down_translation(program, 20);
	}
	else
	{
		copy_pixels_down(program->image, 20);
		calculate_up_translation(program, 20);
	}
	paint_fractal(&program->canvas, program->image, program->fractal);
	return (1);
}
