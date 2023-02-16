/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:18:01 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 16:12:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/canvas.h"

t_fractol_canvas	*set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y)
{
	canvas->end_x = end_x;
	canvas->end_y = end_y;
	return (canvas);
}

t_fractol_canvas	*set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y)
{
	canvas->start_x = start_x;
	canvas->start_y = start_y;
	return (canvas);
}

void	set_base_color(t_fractol_color_controls *color_controls, \
uint8_t r, uint8_t g, uint8_t b)
{
	color_controls->r = r;
	color_controls->g = g;
	color_controls->b = b;
}

void	set_color_factor(t_fractol_color_controls *color_controls, \
double r_factor, double g_factor, double b_factor)
{
	color_controls->r_factor = r_factor;
	color_controls->g_factor = g_factor;
	color_controls->b_factor = b_factor;
}

void	set_potential_factor(t_fractol_color_controls *color_controls, \
int32_t potential_factor)
{
	color_controls->potential_factor = potential_factor;
}