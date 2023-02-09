/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/09 22:12:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PAINTER_H
# define FRACTOL_PAINTER_H

# include "fractol_canvas.h"

typedef enum e_fractol_tracer_direction
{
	TRACER_NORTH,
	TRACER_EAST,
	TRACER_SOUTH,
	TRACER_WEST
}				t_fractol_tracer_direction;

typedef struct s_fractol_tracer
{
	uint32_t					x;
	uint32_t					y;
	uint32_t					start_x;
	uint32_t					start_y;
	t_fractol_tracer_direction	direction;
	t_fractol_tracer_direction	start_direction;
}				t_fractol_tracer;

typedef struct s_fractol_animation
{
	uint32_t	speed;
	bool		border_trace_started;
}				t_fractol_animation;


typedef struct s_fractol_painter
{
	uint32_t			x;
	uint32_t			y;
	t_fractol_animation	animation;
	t_fractol_tracer	tracer;
	t_fractol_complex	c;
	double				border_size;
}				t_fractol_painter;

typedef int	(*t_fractol_painter_func)(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

# define BOUNDARY_COLOR 0xff5555ff
# define INSET_COLOR 0xff

////////////////////////////
///////   painter   ////////
////////////////////////////

int			pixel_is_inset(uint32_t *pixel);

int			pixel_is_empty(uint32_t *pixel);

void		calculate_painter_c(t_fractol_canvas *canvas, \
t_fractol_painter *painter, uint32_t x, uint32_t y);

void		paint_pixel(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal);

void		init_painter(t_fractol_canvas *canvas, t_fractol_painter *painter);

////////////////////////////////////
///////   fractal painter   ////////
////////////////////////////////////

void		paint_inset_pixels(t_fractol_canvas *canvas, \
t_fractol_painter *painter);

int			paint_fractal(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal);

///////////////////////////////////
///////      animation      ///////
///////////////////////////////////

int			animate_fractal(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

int			init_animate_fractal(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

void		init_animation(t_fractol_canvas *canvas, t_fractol_painter *painter);

///////////////////////////////////
///////   border tracing   ////////
///////////////////////////////////

void		border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

void		animate_border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal, uint32_t *iteration);

/////////////////////////////
///////   coloring   ////////
/////////////////////////////

uint32_t	distance_to_color(double value);

/////////////////////////////////
///////    translation   ////////
/////////////////////////////////

void		copy_pixels_right(mlx_image_t *image, uint32_t delta);

void		copy_pixels_left(mlx_image_t *image, uint32_t delta);

void		copy_pixels_down(mlx_image_t *image, uint32_t delta);

void		copy_pixels_up(mlx_image_t *image, uint32_t delta);

#endif