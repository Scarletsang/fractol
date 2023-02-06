/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:15:56 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 04:24:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

int	pixel_is_inset(uint32_t *pixel)
{
	return ((*pixel & 0xFF) == INSET_COLOR);
}

int	pixel_is_empty(uint32_t *pixel)
{
	return ((*pixel & 0xFF) == 0);
}

int	peek_pixel_x_is_inset(t_fractol_canvas *canvas, uint32_t x, uint32_t y)
{
	if ((x >= canvas->end_x) || x < canvas->start_x)
	{
		return (0);
	}
	return (pixel_is_inset(get_pixel(canvas, x, y)));
}
