/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/25 00:06:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_key_hook(mlx_key_data_t keydata, void *viewport)
{
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_LEFT)
	{
		((t_fractol_viewport *) viewport)->real_min -= \
			(((t_fractol_viewport *) viewport)->step * 20);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		((t_fractol_viewport *) viewport)->real_min += \
			(((t_fractol_viewport *) viewport)->step * 20);
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		((t_fractol_viewport *) viewport)->imaginary_max -= \
			(((t_fractol_viewport *) viewport)->step * 20);
	}
	else if (keydata.key == MLX_KEY_UP)
	{
		((t_fractol_viewport *) viewport)->imaginary_max += \
			(((t_fractol_viewport *) viewport)->step * 20);
	}
	draw_mandelbrot(((t_fractol_viewport *) viewport));
}
