/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:28:11 by htsang            #+#    #+#             */
/*   Updated: 2023/02/12 13:40:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"
#include <stdio.h>

void	translate_left_or_right(t_fractol_context *program, \
int32_t horizontal_movement)
{
	if (horizontal_movement > 0)
	{
		calculate_left_translation(&program->canvas, horizontal_movement);
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
	}
	else
	{
		calculate_right_translation(&program->canvas, \
			horizontal_movement * -1);
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
	}
}

void	translate_up_or_down(t_fractol_context *program, \
int32_t vertical_movement)
{
	if (vertical_movement > 0)
	{
		calculate_up_translation(&program->canvas, vertical_movement);
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
	}
	else
	{
		calculate_down_translation(&program->canvas, \
			vertical_movement * -1);
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
	}
}

int	translate(t_fractol_context *program)
{
	t_fractol_pixel_copier	copier;

	if (init_pixel_copier(&copier,\
		(20 * is_triggered(&program->controls, TRANSLATE_UP)) \
		+ (-20 * is_triggered(&program->controls, TRANSLATE_DOWN)),
		(20 * is_triggered(&program->controls, TRANSLATE_LEFT)) \
		+ (-20 * is_triggered(&program->controls, TRANSLATE_RIGHT))))
	{
		return (EXIT_FAILURE);
	}
	copy_pixels(program->canvas.image, &copier);
	translate_up_or_down(program, copier.vertical_movement);
	translate_left_or_right(program, copier.horizontal_movement);
	return (EXIT_SUCCESS);
}

int	translate_viewport(t_fractol_context *program)
{
	int32_t	horizontal_movement;
	int32_t	vertical_movement;

	horizontal_movement = \
		(-1 * is_triggered(&program->controls, TRANSLATE_LEFT)) \
		+ (is_triggered(&program->controls, TRANSLATE_RIGHT));
	vertical_movement = \
		(-1 * is_triggered(&program->controls, TRANSLATE_UP)) \
		+ (is_triggered(&program->controls, TRANSLATE_DOWN));
	if ((vertical_movement == 0) && (horizontal_movement == 0))
	{
		return (EXIT_FAILURE);
	}
	move_viewport_real(&program->canvas, 20, horizontal_movement);
	move_viewport_imaginary(&program->canvas, 20, vertical_movement);
	return (EXIT_SUCCESS);
}
