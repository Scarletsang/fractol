/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_copier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:56:56 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 00:32:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"
#include <stdio.h>

void	copy_pixels_right(mlx_image_t *canvas, uint32_t delta)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	*dest;
	uint32_t	*src;

	y = canvas->height;
	dest = (uint32_t *) canvas->pixels + (canvas->width * canvas->height) - 1;
	src = dest - delta;
	while (y-- > 0)
	{
		x = canvas->width;
		while (x-- > delta)
		{
			*dest-- = *src--;
		}
		dest -= delta;
		src -= delta;
	}
}

void	copy_pixels_left(mlx_image_t *canvas, uint32_t delta)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	*dest;
	uint32_t	*src;

	y = canvas->height;
	dest = (uint32_t *) canvas->pixels;
	src = dest + delta;
	while (y-- > 0)
	{
		x = canvas->width;
		while (x-- > delta)
		{
			*dest++ = *src++;
		}
		dest += delta;
		src += delta;
	}
}

void	copy_pixels_down(mlx_image_t *canvas, uint32_t delta)
{
	uint32_t	*first;
	uint32_t	*dest;
	uint32_t	*src;

	first = (uint32_t *) canvas->pixels;
	dest = first + (canvas->width * canvas->height) - 1;
	src = dest - (canvas->width * delta);
	while (src > first)
	{
		*dest-- = *src--;
	}
	*dest = *src;
}

void	copy_pixels_up(mlx_image_t *canvas, uint32_t delta)
{
	uint32_t	*last;
	uint32_t	*dest;
	uint32_t	*src;

	dest = (uint32_t *) canvas->pixels;
	last = dest + (canvas->width * canvas->height) - 1;
	src = dest + (canvas->width * delta);
	while (src < last)
	{
		*dest++ = *src++;
	}
	*dest = *src;
}
