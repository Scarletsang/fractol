/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 01:11:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PAINTER_H
# define FRACTOL_PAINTER_H

# include "fractol_canvas.h"
# include "limits.h"

typedef struct s_fractol_painter
{
	uint32_t			x;
	uint32_t			y;
	t_fractol_complex	z;
	t_fractol_complex	c;
}				t_fractol_painter;

////////////////////////////
///////   painter   ////////
////////////////////////////

int					paint_fractal(t_fractol_canvas *canvas, mlx_image_t *image, \
t_fractol_func fractal);

int32_t				distance_to_color(double value);

//////////////////////////////////////
///////   pixel translation   ////////
//////////////////////////////////////

void				copy_pixels_right(mlx_image_t *canvas, \
uint32_t delta);

void				copy_pixels_left(mlx_image_t *canvas, \
uint32_t delta);

void				copy_pixels_down(mlx_image_t *canvas, \
uint32_t delta);

void				copy_pixels_up(mlx_image_t *canvas, \
uint32_t delta);

#endif