/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/13 22:27:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_canvas.h"

void	set_base_color(t_fractol_base_color *base_color, \
uint8_t r, uint8_t g, uint8_t b)
{
	base_color->r = r;
	base_color->g = g;
	base_color->b = b;
	base_color->factor = 1000;
}

uint32_t	*get_pixel(t_fractol_canvas *canvas, uint32_t x, uint32_t y)
{
	return ((uint32_t *) canvas->image->pixels + \
		(y * canvas->image->width + x));
}

t_fractol_canvas	*init_canvas(t_fractol_canvas *canvas)
{
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	return (canvas);
}
