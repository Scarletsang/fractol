/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:16:30 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 15:26:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/controls/animation.h"
#include <stdio.h>

void	press_animation_lever(t_fractol_context *program)
{
	if (press_lever(&program->controls, ANIMATION))
	{
		program->painter_func = &paint_fractal;
	}
	else
	{
		program->painter_func = &init_animate_fractal;
	}
	program->painter_func(&program->canvas, &program->painter, \
		program->fractal);
	paint_pixels_from_distance_map(&program->canvas);
}

void	animate(t_fractol_context *program)
{
	if (program->controls == ANIMATION || \
		program->controls == (ANIMATION + COLOR_SHIFT))
	{
		if (animate_fractal(&program->canvas, &program->painter, \
		program->fractal))
		{
			press_lever(&program->controls, ANIMATION);
			program->painter_func = &paint_fractal;
			default_canvas_bounds(&program->canvas);
			program->painter_func(&program->canvas, &program->painter, \
				program->fractal);
		}
	}
	else
	{
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
	}
	paint_pixels_from_distance_map(&program->canvas);
}

void	change_animation_speed(t_fractol_context *program, int increase)
{
	uint32_t	speed_delta;

	speed_delta = program->canvas.image->width / 10;
	if (increase)
	{
		program->painter.animation.speed += speed_delta;
	}
	else
	{
		program->painter.animation.speed -= \
			speed_delta * (program->painter.animation.speed > speed_delta);
	}
}
