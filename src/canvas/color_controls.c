/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:18:01 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 14:41:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/canvas.h"

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
double potential_factor)
{
	color_controls->potential_factor = cos(potential_factor * 0.5f);
	color_controls->potential_factor *= color_controls->potential_factor;
}
