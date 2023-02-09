/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:16:30 by htsang            #+#    #+#             */
/*   Updated: 2023/02/10 00:21:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

void	press_animation_lever(t_fractol_context *program)
{
	if (press_lever(&program->controls, ANIMATION))
	{
		program->painter_func = &paint_fractal;
		paint_fractal(&program->canvas, &program->painter, program->fractal);
	}
	else
	{
		program->painter_func = &init_animate_fractal;
		init_animate_fractal(&program->canvas, &program->painter, \
			program->fractal);
	}
}

void	control_animation(t_fractol_context *program)
{
	if (animate_fractal(&program->canvas, &program->painter, program->fractal))
	{
		press_lever(&program->controls, ANIMATION);
		program->painter_func = &paint_fractal;
	}
}

void	change_animation_speed(t_fractol_context *program, double ydelta)
{
	if (program->painter.animation.speed > 10)
		program->painter.animation.speed += 10 * (-1 * (ydelta < 0));
	else
		program->painter.animation.speed += 10 * (ydelta > 0);
}
