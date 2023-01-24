/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:05:28 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 23:55:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

static t_fractol_viewport	*set_viewport_boundaries( \
t_fractol_viewport *viewport, double center_real, double center_imaginary)
{
	viewport->real_min = center_real - \
		(viewport->step * viewport->canvas->width / 2);
	viewport->imaginary_max = center_imaginary + \
		(viewport->step * viewport->canvas->height / 2);
	return (viewport);
}

t_fractol_viewport	*init_mandelbrot(t_fractol_viewport *viewport, \
mlx_image_t *canvas)
{
	viewport->step = 0.0004;
	viewport->canvas = canvas;
	return (set_viewport_boundaries(viewport, -1.4, 0));
}
