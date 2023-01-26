/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_canvas.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:58:59 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 00:47:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CANVAS_H
# define FRACTOL_CANVAS_H

# include "MLX42/MLX42.h"
# include "fractol_complex.h"

typedef struct s_fractol_canvas
{
	t_fractol_complex	c;
	t_fractol_complex	top_left_corner;
	uint32_t			x;
	uint32_t			y;
	uint32_t			width;
	uint32_t			height;
	uint32_t			left_right_offset;
	uint32_t			*pixels;
	double				pixel_size;
}				t_fractol_canvas;

typedef int	(*t_painter_func)(t_fractol_canvas *canvas);

typedef struct s_fractol_context
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	t_fractol_complex	viewport;
	t_fractol_canvas	canvas;
}				t_fractol_context;

/////////////////////////////////////
///////   viewport setters   ////////
/////////////////////////////////////

t_fractol_context	*set_canvas_dimension(t_fractol_context *program, \
uint32_t width, uint32_t height);

t_fractol_context	*set_canvas_top_left_corner(t_fractol_context *program, \
double real_offset, double imaginary_offset);

t_fractol_context	*set_canvas_pixels(t_fractol_context *program, \
uint32_t offset);

t_fractol_context	*resize_canvas(t_fractol_context *program, \
int32_t width, int32_t height);

///////////////////////////////////////
///////   viewport mutations   ////////
///////////////////////////////////////

t_fractol_context	*set_viewport(t_fractol_context *program, \
double center_real, double center_imaginary);

t_fractol_context	*move_viewport_real(t_fractol_context *program, \
uint32_t pixel_amount, int direction);

t_fractol_context	*move_viewport_imaginary(t_fractol_context *program, \
uint32_t pixel_amount, int direction);

#endif