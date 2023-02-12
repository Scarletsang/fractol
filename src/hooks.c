/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/12 13:50:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	fractol_translation_hook(t_fractol_context *program)
{
	int	translated;

	if (!program->controls)
		return ;
	translated = 0;
	if (is_triggered(&program->controls, CHANGE_Z))
	{
		update_cursor_pos(program);
		convert_cursor_pos_to_complex(program, &program->canvas.z);
	}
	if (is_triggered(&program->controls, ANIMATION))
	{
		
		if ((program->controls & 0b1111) <= 0b1111)
			translate_viewport(program);
		if (program->controls == ANIMATION)
			control_animation(program);
		else
		{
			init_canvas(&program->canvas);
			program->painter_func(\
				&program->canvas, &program->painter, program->fractal);
		}
		if (is_triggered(&program->controls, ZOOM))
			program->controls &= ~ZOOM;
		return ;
	}
	if (is_triggered(&program->controls, ZOOM))
		program->controls &= ~ZOOM;
	if ((program->controls & 0b1111) <= 0b1111)
		translated = !translate(program);
	if (!translated)
	{
		init_canvas(&program->canvas);
		program->painter_func(\
			&program->canvas, &program->painter, program->fractal);
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
		press_switch(&keydata.action, &program->controls, TRANSLATE_LEFT);
	if (keydata.key == MLX_KEY_RIGHT)
		press_switch(&keydata.action, &program->controls, TRANSLATE_RIGHT);
	if (keydata.key == MLX_KEY_DOWN)
		press_switch(&keydata.action, &program->controls, TRANSLATE_DOWN);
	if (keydata.key == MLX_KEY_UP)
		press_switch(&keydata.action, &program->controls, TRANSLATE_UP);
	if (keydata.key == MLX_KEY_Z)
		press_switch(&keydata.action, &program->controls, CHANGE_Z);
	if (keydata.key == MLX_KEY_S && \
		((keydata.action == MLX_PRESS) || (keydata.action == MLX_REPEAT)))
		change_animation_speed(program, keydata.modifier != MLX_SHIFT);
	if ((keydata.key == MLX_KEY_A) && (keydata.action == MLX_PRESS))
		press_animation_lever(program);
}

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program)
{
	if (xdelta)
	{
		print_unsupported_scroll_msg(program->program_name);
		return ;
	}
	update_cursor_pos(program);
	calculate_zoom(program, ydelta);
	program->controls |= ZOOM;
}

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program)
{
	calculate_canvas_resize(&program->canvas, width, height);
	program->painter_func(&program->canvas, &program->painter, \
		program->fractal);
}
