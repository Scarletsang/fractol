/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_calculator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:10:43 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 14:45:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/controls/translation.h"

int	horizontal_translate_canvas_bounds(t_fractol_canvas *canvas, \
int32_t left_movement)
{
	if (left_movement == 0)
		return (EXIT_FAILURE);
	if (left_movement > 0)
	{	
		set_canvas_start(canvas, 0, 0);
		set_canvas_end(canvas, left_movement, canvas->image->height);
	}
	else
	{
		set_canvas_start(canvas, canvas->image->width + left_movement, 0);
		set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	}
	return (EXIT_SUCCESS);
}

int	vertical_translate_canvas_bounds(t_fractol_canvas *canvas, \
int32_t up_movement)
{
	if (up_movement == 0)
		return (EXIT_FAILURE);
	if (up_movement > 0)
	{
		set_canvas_start(canvas, 0, 0);
		set_canvas_end(canvas, canvas->image->width, up_movement);
	}
	else
	{
		set_canvas_start(canvas, 0, canvas->image->height + up_movement);
		set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	}
	return (EXIT_SUCCESS);
}

void	adjust_vertical_translation(t_fractol_canvas *canvas, \
int32_t left_movement)
{
	if (left_movement > 0)
	{
		canvas->start_x += left_movement;
	}
	else if (left_movement < 0)
	{
		canvas->end_x += left_movement;
	}
}

t_fractol_canvas	*calculate_canvas_resize(t_fractol_canvas *canvas, \
int32_t width, int32_t height)
{
	mlx_resize_image(canvas->image, width, height);
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, width, height);
	return (canvas);
}
