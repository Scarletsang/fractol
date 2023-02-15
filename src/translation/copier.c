/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:39:47 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 00:25:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/controls/translation.h"

void	copy_pixel(uint32_t *dest, uint32_t *src);

void	copy_distance_point(t_fractol_distance *dest, t_fractol_distance *src);

static void	copy_pixels_from_start(t_fractol_canvas *canvas, \
t_fractol_copier *copier, int32_t element_size, \
t_fractol_copier_func copier_func)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	i;
	uint32_t	xdelta;

    if (copier->left_movement < 0)
        copier->src = (char *)copier->src - \
			(copier->left_movement * element_size);
    else if (copier->left_movement > 0)
        copier->dest = (char *)copier->dest + \
			(copier->left_movement * element_size);
	xdelta = abs(copier->left_movement);
	y = canvas->image->height - abs(copier->up_movement);
	i = 0;
	while (y-- > 0)
	{
		x = canvas->image->width - xdelta;
		while (x-- > 0)
		{
			copier_func((char *)copier->dest + i, (char *)copier->src + i);
			i += element_size;
		}
		i += (xdelta * element_size);
	}
}

static void	copy_pixels_from_bottom(t_fractol_canvas *canvas, \
t_fractol_copier *copier, int32_t element_size, \
t_fractol_copier_func copier_func)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	i;
	uint32_t	xdelta;

    if (copier->left_movement < 0)
        copier->dest = (char *)copier->dest + \
			(copier->left_movement * element_size);
    else if (copier->left_movement > 0)
        copier->src = (char *)copier->src - \
			(copier->left_movement * element_size);
	xdelta = abs(copier->left_movement);
	y = canvas->image->height - copier->up_movement;
	i = 0;
	while (y-- > 0)
	{
		x = canvas->image->width - xdelta;
		while (x-- > 0)
		{
			copier_func((char *)copier->dest - i, (char *)copier->src - i);
			i += element_size;
		}
		i += (xdelta * element_size);
	}
}

void	copy_pixels(t_fractol_canvas *canvas, t_fractol_copier *copier)
{
	if (copier->up_movement > 0 || \
		((copier->left_movement > 0) && (copier->up_movement == 0)))
	{
		copier->dest = (uint32_t *) canvas->image->pixels + \
			((canvas->image->width * canvas->image->height) - 1);
		copier->src = (uint32_t *) copier->dest - \
			(canvas->image->width * copier->up_movement);
		copy_pixels_from_bottom(canvas, copier, sizeof(uint32_t), \
			(t_fractol_copier_func) copy_pixel);
	}
	else
	{
		copier->dest = (uint32_t *) canvas->image->pixels;
		copier->src = (uint32_t *) copier->dest + \
			(canvas->image->width * abs(copier->up_movement));
		copy_pixels_from_start(canvas, copier, sizeof(uint32_t), \
			(t_fractol_copier_func) copy_pixel);
	}
}

void	copy_distance_points(t_fractol_canvas *canvas, t_fractol_copier *copier)
{
	if (copier->up_movement > 0 || \
		((copier->left_movement > 0) && (copier->up_movement == 0)))
	{
		copier->dest = canvas->distance_map + \
			((canvas->image->width * canvas->image->height) - 1);
		copier->src = (t_fractol_distance *) copier->dest - \
			(canvas->image->width * copier->up_movement);
		copy_pixels_from_bottom(canvas, copier, sizeof(t_fractol_distance *), \
			(t_fractol_copier_func) copy_distance_point);
	}
	else
	{
		copier->dest = canvas->distance_map;
		copier->src = (t_fractol_distance *) copier->dest + \
			(canvas->image->width * abs(copier->up_movement));
		copy_pixels_from_start(canvas, copier, sizeof(t_fractol_distance *), \
			(t_fractol_copier_func) copy_distance_point);
	}
}
