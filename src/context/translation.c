/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:28:11 by htsang            #+#    #+#             */
/*   Updated: 2023/01/28 00:40:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

void	translate_left_or_right(unsigned int arrow_keys, \
t_fractol_context *program)
{
	if (!arrow_keys || arrow_keys == 0b0011)
	{
		return ;
	}
	if ((arrow_keys & 0b0001) == 0b0001)
	{
		copy_pixels_right(program->image, 20);
		calculate_left_translation(program, 20);
	}
	else
	{
		copy_pixels_left(program->image, 20);
		calculate_right_translation(program, 20);
	}
	paint_fractal(&program->canvas, program->fractal);
}

void	translate_up_or_down(unsigned int arrow_keys, \
t_fractol_context *program)
{
	if (!arrow_keys || arrow_keys == 0b0011)
	{
		return ;
	}
	if ((arrow_keys & 0b0001) == 0b0001)
	{
		copy_pixels_up(program->image, 20);
		calculate_down_translation(program, 20);
	}
	else
	{
		copy_pixels_down(program->image, 20);
		calculate_up_translation(program, 20);
	}
	paint_fractal(&program->canvas, program->fractal);
}
