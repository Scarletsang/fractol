/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/12 23:58:47 by htsang           ###   ########.fr       */
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

typedef struct s_fractol_pixel_copier
{
	uint32_t	*dest;
	uint32_t	*src;
	int32_t		up_movement;
	int32_t		left_movement;
}				t_fractol_pixel_copier;

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

void		init_animation(t_fractol_canvas *canvas, \
t_fractol_painter *painter);

///////////////////////////////////
///////   border tracing   ////////
///////////////////////////////////

void		border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

void		animate_border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal, uint32_t *iteration);

void		init_animate_border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

/////////////////////////////
///////   coloring   ////////
/////////////////////////////

uint32_t	distance_to_color(double value);

/////////////////////////////////
///////    translation   ////////
/////////////////////////////////

void		copy_pixels(mlx_image_t *image, t_fractol_pixel_copier *copier);

#endif