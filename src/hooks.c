/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 03:55:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	fractol_translation_hook(t_fractol_context *program)
{
	int	painted;

	if (!program->controls)
		return ;
	update_cursor_pos(program);
	if ((program->controls & CHANGE_Z) == CHANGE_Z)
	{
		convert_cursor_pos_to_complex(program, &program->canvas.z);
	}
	painted = translate_left_or_right(&program->canvas, \
		program->fractal, program->controls & 0b0011);
	painted += translate_up_or_down(&program->canvas, \
		program->fractal, program->controls & 0b1100);
	if (!painted)
	{
		init_canvas(&program->canvas);
		paint_fractal(&program->canvas, program->fractal);
	}
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
	if (keydata.key == MLX_KEY_Z)
	{
		set_controls(&keydata.action, &program->controls, CHANGE_Z);
	}
}

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program)
{
	if (ydelta)
	{
		update_cursor_pos(program);
		calculate_zoom(program, ydelta);
		paint_fractal(&program->canvas, program->fractal);
	}
	else if (xdelta)
	{
		update_cursor_pos(program);
		calculate_zoom(program, xdelta);
		paint_fractal(&program->canvas, program->fractal);
	}
}

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program)
{
	resize_canvas(&program->canvas, width, height);
	paint_fractal(&program->canvas, program->fractal);
}
