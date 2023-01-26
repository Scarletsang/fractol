/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 01:38:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"

static void	fractol_translation_control(mlx_key_data_t keydata, \
t_fractol_hook_ctx *hook_ctx)
{
	print_viewport(&hook_ctx->viewport);
	if (keydata.key == MLX_KEY_LEFT)
	{
		move_real_axis_by(&hook_ctx->viewport, 20, -1);
		copy_pixels_right(hook_ctx->viewport.canvas, 20);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		move_real_axis_by(&hook_ctx->viewport, 20, 1);
		copy_pixels_left(hook_ctx->viewport.canvas, 20);
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		move_imaginary_axis_by(&hook_ctx->viewport, 20, -1);
		copy_pixels_up(hook_ctx->viewport.canvas, 20);
	}
	else if (keydata.key == MLX_KEY_UP)
	{
		move_imaginary_axis_by(&hook_ctx->viewport, 20, 1);
		copy_pixels_down(hook_ctx->viewport.canvas, 20);
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
	fractol_translation_control(keydata, (t_fractol_hook_ctx *)hook_ctx);
}

void	fractol_resize_hook(int32_t width, int32_t height, void *hook_ctx)
{
	resize_viewport(&((t_fractol_hook_ctx *) hook_ctx)->viewport, \
		width, height);
	draw_mandelbrot(&((t_fractol_hook_ctx *) hook_ctx)->viewport);
}
