/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 14:10:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_translation_control(mlx_key_data_t keydata, \
t_fractol_context *program)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		move_real_axis_by(&program->viewport, 20, -1);
		copy_pixels_right(program->canvas, 20);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		move_real_axis_by(&program->viewport, 20, 1);
		copy_pixels_left(program->canvas, 20);
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		move_imaginary_axis_by(&program->viewport, 20, -1);
		copy_pixels_up(program->canvas, 20);
	}
	else if (keydata.key == MLX_KEY_UP)
	{
		move_imaginary_axis_by(&program->viewport, 20, 1);
		copy_pixels_down(program->canvas, 20);
	}
}

void	fractol_key_hook(mlx_key_data_t keydata, void *hook_ctx)
{
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(((t_fractol_context *)hook_ctx)->mlx);
		return ;
	}
	fractol_translation_control(keydata, (t_fractol_context *)hook_ctx);
}

void	fractol_resize_hook(int32_t width, int32_t height, void *program)
{
	resize_viewport((t_fractol_context *) program, width, height);
	draw_mandelbrot(&((t_fractol_context *) program)->viewport);
}
