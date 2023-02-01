/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:46:35 by htsang            #+#    #+#             */
/*   Updated: 2023/01/31 22:39:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

t_fractol_context	*calculate_zoom(t_fractol_context *program, double ydelta)
{
	double				zoom_percentage;
	t_fractol_complex	mouse;
	int32_t				mouse_x;
	int32_t				mouse_y;

	mlx_get_mouse_pos(program->mlx, &mouse_x, &mouse_y);
	set_complex_number(&mouse, \
		program->viewport.real + \
			(mouse_x * program->canvas.settings.pixel_size), \
		program->viewport.imaginary - \
			(mouse_y * program->canvas.settings.pixel_size));
	zoom_percentage = fabs(ydelta) / 50 ;
	zoom_percentage *= program->canvas.settings.pixel_size;
	if (ydelta < 0)
		zoom_percentage *= -1;
	program->canvas.settings.pixel_size += zoom_percentage;
	return (init_fractal(program, program->fractal, \
		mouse.real - (mouse_x * program->canvas.settings.pixel_size), \
		mouse.imaginary + (mouse_y * program->canvas.settings.pixel_size)));
}
