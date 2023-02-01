/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 02:14:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_translation_hook(t_fractol_context *program)
{
	if (!program->controls)
		return ;
	translate_left_or_right(program->controls & 0b0011, program);
	translate_up_or_down(program->controls >> 2, program);
}

void	fractol_key_hook(mlx_key_data_t keydata, t_fractol_context *program)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(program->mlx);
		return ;
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		set_controls(&keydata.action, &program->controls, TRANSLATE_LEFT);
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		set_controls(&keydata.action, &program->controls, TRANSLATE_RIGHT);
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		set_controls(&keydata.action, &program->controls, TRANSLATE_DOWN);
	}
	if (keydata.key == MLX_KEY_UP)
	{
		set_controls(&keydata.action, &program->controls, TRANSLATE_UP);
	}
}

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program)
{
	if (ydelta)
	{
		calculate_zoom(program, ydelta);
		paint_fractal(&program->canvas, program->image, program->fractal);
	}
	else if (xdelta)
	{
		calculate_zoom(program, xdelta);
		paint_fractal(&program->canvas, program->image, program->fractal);
	}
}

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program)
{
	resize_canvas(program, width, height);
	paint_fractal(&program->canvas, program->image, program->fractal);
}
