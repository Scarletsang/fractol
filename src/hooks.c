/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 23:55:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_translation_control(mlx_key_data_t keydata, \
t_fractol_context *program, uint32_t delta)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		copy_pixels_right(program->image, delta);
		translate_viewport_left(program, delta);
		draw_mandelbrot(&program->canvas);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		copy_pixels_left(program->image, delta);
		translate_viewport_right(program, delta);
		draw_mandelbrot(&program->canvas);
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		copy_pixels_up(program->image, delta);
		translate_viewport_down(program, delta);
		draw_mandelbrot(&program->canvas);
	}
	else if (keydata.key == MLX_KEY_UP)
	{
		copy_pixels_down(program->image, delta);
		translate_viewport_up(program, delta);
		draw_mandelbrot(&program->canvas);
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
	fractol_translation_control(keydata, (t_fractol_context *)hook_ctx, 20);
}

void	fractol_resize_hook(int32_t width, int32_t height, void *program)
{
	resize_canvas((t_fractol_context *) program, width, height);
	draw_mandelbrot(&((t_fractol_context *) program)->canvas);
}
