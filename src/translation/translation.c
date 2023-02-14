/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:28:11 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:53:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/controls/translation.h"

static int	set_translation_vector(unsigned int *controls, int32_t *left_movement, \
int32_t *up_movement, int speed)
{
	*left_movement = \
		(speed * is_triggered(controls, TRANSLATE_LEFT)) \
		+ (-speed * is_triggered(controls, TRANSLATE_RIGHT));
	*up_movement = \
		(speed * is_triggered(controls, TRANSLATE_UP)) \
		+ (-speed * is_triggered(controls, TRANSLATE_DOWN));
	if ((*up_movement == 0) && (*left_movement == 0))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	translate(t_fractol_context *program)
{
	t_fractol_pixel_copier	copier;

	if (set_translation_vector(\
		&program->controls, &copier.left_movement, &copier.up_movement, 20))
		return (EXIT_FAILURE);
	move_viewport_real(&program->canvas, copier.left_movement * -1);
	move_viewport_imaginary(&program->canvas, copier.up_movement);
	copy_pixels(program->canvas.image, &copier);
	if (!calculate_vertical_translation(&program->canvas, \
		copier.up_movement))
	{
		adjust_vertical_translation(&program->canvas, \
			copier.left_movement);
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
	}
	if (!calculate_horizontal_translation(&program->canvas, \
		copier.left_movement))
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
	return (EXIT_SUCCESS);
}

int	translate_viewport(t_fractol_context *program)
{
	int32_t	left_movement;
	int32_t	up_movement;

	if (set_translation_vector(\
		&program->controls, &left_movement, &up_movement, 20))
		return (EXIT_FAILURE);
	move_viewport_real(&program->canvas, left_movement * -1);
	move_viewport_imaginary(&program->canvas, up_movement);
	return (EXIT_SUCCESS);
}
