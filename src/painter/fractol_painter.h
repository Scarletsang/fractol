/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/02 21:43:45 by htsang           ###   ########.fr       */
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
	t_fractol_complex	c;
	t_fractol_complex	complex_end;
	double				border_size;
	t_fractol_tracer	tracer;
}				t_fractol_painter;

typedef enum e_fractol_tracer_dir
{
	TRACER_UP,
	TRACER_RIGHT,
	TRACER_DOWN,
	TRACER_LEFT
}				t_fractol_tracer_dir;

typedef struct s_fractol_tracer
{
	t_fractol_tracer_dir	direction;
	int						step;
	uint32_t				x;
	uint32_t				y;
}				t_fractol_tracer;

# define BOUNDARY_COLOR 0xff5555FF
# define INSET_COLOR 0

////////////////////////////
///////   painter   ////////
////////////////////////////

void	init_painter(t_fractol_painter *painter, \
t_fractol_canvas *canvas);

int32_t	paint_fractal(t_fractol_canvas *canvas, mlx_image_t *image, \
t_fractol_func fractal);

int32_t	border_trace_fractal(t_fractol_canvas *canvas, t_fractol_func fractal);

int32_t	distance_to_color(double value);

//////////////////////////////////////
///////   pixel translation   ////////
//////////////////////////////////////

void	copy_pixels_right(mlx_image_t *canvas, \
uint32_t delta);

void	copy_pixels_left(mlx_image_t *canvas, \
uint32_t delta);

void	copy_pixels_down(mlx_image_t *canvas, \
uint32_t delta);

void	copy_pixels_up(mlx_image_t *canvas, \
uint32_t delta);

#endif