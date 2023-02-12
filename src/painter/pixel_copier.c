/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_copier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:56:56 by htsang            #+#    #+#             */
/*   Updated: 2023/02/12 04:24:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

static void	copy_pixels_from_start(mlx_image_t *image, \
t_fractol_pixel_copier *copier)
{
	uint32_t	x;
	uint32_t	y;

	if (copier->horizontal_movement < 0)
	{
		copier->horizontal_movement *= -1;
		copier->src += copier->horizontal_movement;
	}
	else if (copier->horizontal_movement > 0)
		copier->dest += copier->horizontal_movement;
	y = image->height - copier->vertical_movement;
	while (y-- > 0)
	{
		x = image->width - copier->horizontal_movement;
		while (x-- > 0)
		{
			*copier->dest++ = *copier->src++;
		}
		copier->dest += copier->horizontal_movement;
		copier->src += copier->horizontal_movement;
	}
}

static void	copy_pixels_from_bottom(mlx_image_t *image, \
t_fractol_pixel_copier *copier)
{
	uint32_t	x;
	uint32_t	y;

	if (copier->horizontal_movement < 0)
	{
		copier->horizontal_movement *= -1;
		copier->dest -= copier->horizontal_movement;
	}
	else if (copier->horizontal_movement > 0)
		copier->src -= copier->horizontal_movement;
	y = image->height - copier->vertical_movement;
	while (y-- > 0)
	{
		x = image->width - copier->horizontal_movement;
		while (x-- > 0)
		{
			*copier->dest-- = *copier->src--;
		}
		copier->dest -= copier->horizontal_movement;
		copier->src -= copier->horizontal_movement;
	}
}

void	copy_pixels(mlx_image_t *image, t_fractol_pixel_copier *copier)
{
	if (copier->vertical_movement > 0 || \
		((copier->horizontal_movement > 0) && (copier->vertical_movement == 0)))
	{
		copier->dest = (uint32_t *) image->pixels + \
			(image->width * image->height) - 1;
		copier->src = copier->dest - (image->width * copier->vertical_movement);
		copy_pixels_from_bottom(image, copier);
	}
	else
	{
		copier->vertical_movement *= -1;
		copier->dest = (uint32_t *) image->pixels;
		copier->src = copier->dest + (image->width * copier->vertical_movement);
		copy_pixels_from_start(image, copier);
	}
}

int	init_pixel_copier(t_fractol_pixel_copier *copier, int32_t vertical_movement, \
int32_t horizontal_movement)
{
	copier->vertical_movement = vertical_movement;
	copier->horizontal_movement = horizontal_movement;
	if ((vertical_movement == 0) && (horizontal_movement == 0))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
