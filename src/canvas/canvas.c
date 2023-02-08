/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:24 by htsang            #+#    #+#             */
/*   Updated: 2023/02/08 01:23:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_canvas.h"

uint32_t	*get_pixel(t_fractol_canvas *canvas, uint32_t x, uint32_t y)
{
	return ((uint32_t *) canvas->image->pixels + (y * canvas->image->width + x));
}

t_fractol_canvas	*init_canvas(t_fractol_canvas *canvas)
{
	set_canvas_start(canvas, 0, 0);
	set_canvas_end(canvas, canvas->image->width, canvas->image->height);
	set_canvas_complex_start(canvas, 0, 0);
	return (canvas);
}
