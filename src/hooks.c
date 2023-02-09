/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/10 00:23:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

void	fractol_translation_hook(t_fractol_context *program)
{
	int	painted;

	if (!program->controls)
		return ;
	if (is_triggered(&program->controls, CHANGE_Z))
	{
		painted = 0;
		update_cursor_pos(program);
		convert_cursor_pos_to_complex(program, &program->canvas.z);
	}
	if (program->controls <= 15)
		painted = translate(program);
	if (is_triggered(&program->controls, ANIMATION))
	{
		control_animation(program);
	}
	else if (!painted)
	{
		init_canvas(&program->canvas);
		program->painter_func( \
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
	if ((keydata.key == MLX_KEY_A) && (keydata.action == MLX_PRESS))
		press_animation_lever(program);
}

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program)
{
	if (xdelta)
	{
		write(STDERR_FILENO, "horizontal scrolling is not supported.", 39);
		return ;
	}
	if (is_triggered(&program->controls, ANIMATION))
	{
		change_animation_speed(program, ydelta);
	}
	else
	{
		update_cursor_pos(program);
		calculate_zoom(program, ydelta);
		program->painter_func(&program->canvas, &program->painter, program->fractal);
	}
}

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program)
{
	calculate_canvas_resize(&program->canvas, width, height);
	program->painter_func(&program->canvas, &program->painter, program->fractal);
}
