/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 01:37:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PAINTER_H
# define FRACTOL_PAINTER_H

# include "MLX42/MLX42.h"
# include "limits.h"
# include "fractol_complex.h"

# ifndef BORDER_THICKNESS
#  define BORDER_THICKNESS 0.01
# endif

typedef struct s_fractol_complex_states
{
	double				real_min;
	double				imaginary_max;
	t_fractol_complex	z;
	t_fractol_complex	c;
}				t_fractol_complex_states;

typedef struct s_fractol_painter_states
{
	double		pixel_size;
	uint32_t	x;
	uint32_t	y;
	uint32_t	width;
	uint32_t	height;
	uint32_t	*pixels;
}				t_fractol_painter_states;

typedef struct s_fractol_viewport
{
	t_fractol_complex_states	math;
	t_fractol_painter_states	painter;
	mlx_image_t					*canvas;
}				t_fractol_viewport;

typedef int	(*t_painter_func)(t_fractol_viewport *viewport);

/////////////////////////////
///////   viewport   ////////
/////////////////////////////

t_fractol_viewport	*set_painter_pixels(t_fractol_viewport *viewport, \
uint32_t offset);

t_fractol_viewport	*set_viewport_boundaries( t_fractol_viewport *viewport, \
double center_real, double center_imaginary);

t_fractol_viewport	*move_real_axis_by(t_fractol_viewport *viewport, \
uint32_t pixel_amount, int direction);

t_fractol_viewport	*move_imaginary_axis_by(t_fractol_viewport *viewport, \
uint32_t pixel_amount, int direction);

t_fractol_viewport	*resize_viewport(t_fractol_viewport *viewport, \
int32_t width, int32_t height);

/////////////////////////////////////
///////   mandelbrot's set   ////////
/////////////////////////////////////

int					draw_mandelbrot(t_fractol_viewport *viewport);

t_fractol_viewport	*init_mandelbrot(t_fractol_viewport *viewport, \
mlx_image_t *canvas);

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