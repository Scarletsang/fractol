/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_copier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:56:56 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:32:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol/controls/translation.h"

static void	copy_pixels_from_start(mlx_image_t *image, \
t_fractol_pixel_copier *copier)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	xdelta;

	if (copier->left_movement < 0)
	{
		copier->src -= copier->left_movement;
	}
	else if (copier->left_movement > 0)
		copier->dest += copier->left_movement;
	xdelta = abs(copier->left_movement);
	y = image->height - abs(copier->up_movement);
	while (y-- > 0)
	{
		x = image->width - xdelta;
		while (x-- > 0)
		{
			*copier->dest++ = *copier->src++;
		}
		copier->dest += xdelta;
		copier->src += xdelta;
	}
}

static void	copy_pixels_from_bottom(mlx_image_t *image, \
t_fractol_pixel_copier *copier)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	xdelta;

	if (copier->left_movement < 0)
	{
		copier->dest += copier->left_movement;
	}
	else if (copier->left_movement > 0)
		copier->src -= copier->left_movement;
	xdelta = abs(copier->left_movement);
	y = image->height - copier->up_movement;
	while (y-- > 0)
	{
		x = image->width - xdelta;
		while (x-- > 0)
		{
			*copier->dest-- = *copier->src--;
		}
		copier->dest -= xdelta;
		copier->src -= xdelta;
	}
}

void	copy_pixels(mlx_image_t *image, t_fractol_pixel_copier *copier)
{
	if (copier->up_movement > 0 || \
		((copier->left_movement > 0) && (copier->up_movement == 0)))
	{
		copier->dest = (uint32_t *) image->pixels + \
			(image->width * image->height) - 1;
		copier->src = copier->dest - (image->width * copier->up_movement);
		copy_pixels_from_bottom(image, copier);
	}
	else
	{
		copier->dest = (uint32_t *) image->pixels;
		copier->src = copier->dest + (image->width * abs(copier->up_movement));
		copy_pixels_from_start(image, copier);
	}
}
