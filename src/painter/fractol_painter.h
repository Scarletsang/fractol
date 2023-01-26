/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 14:14:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PAINTER_H
# define FRACTOL_PAINTER_H

# include "fractol_viewport.h"
# include "limits.h"

# ifndef BORDER_THICKNESS
#  define BORDER_THICKNESS 0.01
# endif

/////////////////////////////////////
///////   mandelbrot's set   ////////
/////////////////////////////////////

int					draw_mandelbrot(t_fractol_viewport *viewport);

t_fractol_context	*init_mandelbrot(t_fractol_context *program);

uint32_t			distance_to_color(double value);

////////////////////////////////
///////   translation   ////////
////////////////////////////////

void				copy_pixels_right(mlx_image_t *canvas, \
uint32_t delta);

void				copy_pixels_left(mlx_image_t *canvas, \
uint32_t delta);

void				copy_pixels_down(mlx_image_t *canvas, \
uint32_t delta);

void				copy_pixels_up(mlx_image_t *canvas, \
uint32_t delta);

#endif