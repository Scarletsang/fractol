/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/07 16:24:19 by htsang           ###   ########.fr       */
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
	t_fractol_tracer_direction	direction;
	uint32_t					step;
}				t_fractol_tracer;

typedef struct s_fractol_painter
{
	uint32_t			x;
	uint32_t			y;
	t_fractol_complex	c;
	double				border_size;
}				t_fractol_painter;

# define BOUNDARY_COLOR 0xff5555ff
# define INSET_COLOR 0xff

////////////////////////////
///////   painter   ////////
////////////////////////////

void		calculate_painter_c(t_fractol_canvas *canvas, \
t_fractol_painter *painter);

void		paint_pixel(t_fractol_canvas *canvas, t_fractol_painter *painter, \
t_fractol_func fractal);

void		init_painter(t_fractol_canvas *canvas, t_fractol_painter *painter);

int32_t		paint_fractal(t_fractol_canvas *canvas, t_fractol_func fractal);

///////////////////////////////////
///////   border tracing   ////////
///////////////////////////////////

int			moore_neighbours(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_tracer *tracer, t_fractol_func fractal);

void		border_trace(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

/////////////////////////////////////////////////
///////   moore neighbours calculators   ////////
/////////////////////////////////////////////////

int			prepare_trace_north(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_tracer *tracer);

int			prepare_trace_east(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_tracer *tracer);

int			prepare_trace_south(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_tracer *tracer);

int			prepare_trace_west(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_tracer *tracer);

//////////////////////////////
///////   checkers   /////////
//////////////////////////////

int			pixel_is_inset(uint32_t *pixel);

int			pixel_is_empty(uint32_t *pixel);

/////////////////////////////
///////   coloring   ////////
/////////////////////////////

uint32_t	distance_to_color(double value);

//////////////////////////////////////
///////   pixel translation   ////////
//////////////////////////////////////

void		copy_pixels_right(mlx_image_t *image, uint32_t delta);

void		copy_pixels_left(mlx_image_t *image, uint32_t delta);

void		copy_pixels_down(mlx_image_t *image, uint32_t delta);

void		copy_pixels_up(mlx_image_t *image, uint32_t delta);

#endif