/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/28 00:51:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "unistd.h"

void	fractol_translation_hook(t_fractol_context *program)
{
	if (!program->arrow_keys)
		return ;
	translate_left_or_right(program->arrow_keys & 0b0011, program);
	translate_up_or_down(program->arrow_keys >> 2, program);
}

void	set_arrow_keys(action_t *action, unsigned int *arrow_keys, \
unsigned int when_press, unsigned int when_release)
{
	if (*action == MLX_PRESS)
		*arrow_keys |= when_press;
	if (*action == MLX_RELEASE)
		*arrow_keys &= when_release;
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
		set_arrow_keys(&keydata.action, &program->arrow_keys, 0b0001, 0b1110);
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		set_arrow_keys(&keydata.action, &program->arrow_keys, 0b0010, 0b1101);
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		set_arrow_keys(&keydata.action, &program->arrow_keys, 0b0100, 0b1011);
	}
	if (keydata.key == MLX_KEY_UP)
	{
		set_arrow_keys(&keydata.action, &program->arrow_keys, 0b1000, 0b0111);
	}
}

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program)
{
	resize_canvas(program, width, height);
	paint_fractal(&program->canvas, program->fractal);
}
