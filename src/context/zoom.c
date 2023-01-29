/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:46:35 by htsang            #+#    #+#             */
/*   Updated: 2023/01/29 23:55:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"
#include <stdio.h>

void	zoom(t_fractol_context *program, double ydelta)
{
	double	zoom_percentage;
	int32_t	mouse_x;
	int32_t	mouse_y;

	mlx_get_mouse_pos(program->mlx, &mouse_x, &mouse_y);
	zoom_percentage = 1 - (1 / (fabs(ydelta) + 1));
	if (ydelta < 0)
	{
		program->canvas.settings.pixel_size *= zoom_percentage;
	}
	else
	{
		program->canvas.settings.pixel_size /= zoom_percentage;
	}
	// init_fractal(program, program->fractal, \
	// 	program->viewport.real, program->viewport.imaginary);
	init_fractal(program, program->fractal, \
		program->viewport.real + \
			((mouse_x * program->canvas.settings.pixel_size - program->viewport.real) * zoom_percentage),
		program->viewport.imaginary + \
			((mouse_y * program->canvas.settings.pixel_size - program->viewport.imaginary) * zoom_percentage));
}