/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:16:30 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:31:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol/controls/animation.h"

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
}

void	control_animation(t_fractol_context *program)
{
	if (animate_fractal(&program->canvas, &program->painter, program->fractal))
	{
		press_lever(&program->controls, ANIMATION);
		program->painter_func = &paint_fractal;
		program->painter_func(&program->canvas, &program->painter, \
			program->fractal);
	}
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
