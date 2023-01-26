/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_viewport.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:58:59 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 14:09:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_VIEWPORT_H
# define FRACTOL_VIEWPORT_H

# include "MLX42/MLX42.h"
# include "fractol_complex.h"

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
}				t_fractol_viewport;

typedef int	(*t_painter_func)(t_fractol_viewport *viewport);

typedef struct s_fractol_context
{
	mlx_t				*mlx;
	mlx_image_t			*canvas;
	t_fractol_viewport	viewport;
}				t_fractol_context;


/////////////////////////////////////
///////   viewport setters   ////////
/////////////////////////////////////

t_fractol_context	*set_viewport_boundaries( t_fractol_context *program, \
double center_real, double center_imaginary);

t_fractol_context	*set_painter_pixels(t_fractol_context *program, \
uint32_t offset);

t_fractol_context	*resize_viewport(t_fractol_context *program, \
int32_t width, int32_t height);

///////////////////////////////////////
///////   viewport mutations   ////////
///////////////////////////////////////

t_fractol_viewport	*move_real_axis_by(t_fractol_viewport *viewport, \
uint32_t pixel_amount, int direction);

t_fractol_viewport	*move_imaginary_axis_by(t_fractol_viewport *viewport, \
uint32_t pixel_amount, int direction);

#endif