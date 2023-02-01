/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:46:35 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 15:55:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

t_fractol_context	*calculate_zoom(t_fractol_context *program, double ydelta)
{
	double				zoom_percentage;
	t_fractol_complex	mouse;

	convert_cursor_pos_to_complex(program, &mouse);
	zoom_percentage = (fabs(ydelta) / 50) * program->canvas.settings.pixel_size;
	if (ydelta < 0)
		zoom_percentage *= -1;
	program->canvas.settings.pixel_size += zoom_percentage;
	return (init_fractal(program, program->fractal, \
		mouse.real - (program->mouse_x * program->canvas.settings.pixel_size), \
		mouse.imaginary + \
		(program->mouse_y * program->canvas.settings.pixel_size)));
}
