/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:58:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 19:34:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CANVAS_H
# define FRACTOL_CANVAS_H

# include "MLX42/MLX42.h"
# include "FRACTOL/complex.h"

typedef struct s_fractol_color_controls
{
	uint8_t	r;
	uint8_t	b;
	uint8_t	g;
	int32_t	potential_factor;
	double	r_factor;
	double	g_factor;
	double	b_factor;
}				t_fractol_color_controls;

typedef struct s_fractol_canvas
{
	uint32_t						start_x;
	uint32_t						start_y;
	uint32_t						end_x;
	uint32_t						end_y;
	double							pixel_size;
	double							border_thickness;
	t_fractol_color_controls		color_controls;
	t_fractol_complex				viewport;
	t_fractol_distance_estimator	estimator;
	t_fractol_distance				*distance_map;
	mlx_image_t						*image;
}				t_fractol_canvas;

///////////////////////////
///////   canvas   ////////
///////////////////////////

t_fractol_canvas	*init_canvas(t_fractol_canvas *canvas);

uint32_t			*get_pixel(t_fractol_canvas *canvas, \
uint32_t x, uint32_t y);

t_fractol_canvas	*set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y);

t_fractol_canvas	*set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y);

void				set_base_color(t_fractol_color_controls *color_controls, \
uint8_t r, uint8_t g, uint8_t b);

/////////////////////////////
///////   viewport   ////////
/////////////////////////////

void				move_viewport_real(t_fractol_canvas *canvas, \
int32_t pixel_amount);

void				move_viewport_imaginary(t_fractol_canvas *canvas, \
int32_t pixel_amount);

/////////////////////////////////
///////   distance map   ////////
/////////////////////////////////

int					point_is_inset(t_fractol_distance *distance_point);

int					point_is_empty(t_fractol_distance *distance_point);

t_fractol_canvas	*set_distance_map_empty(t_fractol_canvas *canvas);

t_fractol_distance	*get_distance_map_point(t_fractol_canvas *canvas, \
uint32_t x, uint32_t y);

void				malloc_distance_map(t_fractol_canvas *canvas);

#endif