/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_canvas.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:58:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/04 03:58:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CANVAS_H
# define FRACTOL_CANVAS_H

# include "MLX42/MLX42.h"
# include "fractol_complex.h"

typedef struct s_fractol_canvas_setting
{
	uint32_t	iteration;
	double		pixel_size;
	double		border_thickness;
}				t_fractol_canvas_setting;

typedef struct s_fractol_canvas
{
	uint32_t					start_x;
	uint32_t					start_y;
	uint32_t					end_x;
	uint32_t					end_y;
	t_fractol_complex			z;
	t_fractol_complex			complex_start;
	t_fractol_complex			viewport;
	t_fractol_canvas_setting	settings;
	mlx_image_t					*image;
}				t_fractol_canvas;

///////////////////////////
///////   canvas   ////////
///////////////////////////

t_fractol_canvas	*init_canvas(t_fractol_canvas *canvas);

uint32_t			*get_pixel(t_fractol_canvas *canvas, \
uint32_t x, uint32_t y);

uint32_t			*safe_get_pixel_horizontal(t_fractol_canvas *canvas, \
uint32_t x, uint32_t y);

t_fractol_canvas	*set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y);

t_fractol_canvas	*set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y);

t_fractol_canvas	*set_canvas_complex_start(t_fractol_canvas *canvas, \
double real_offset, double imaginary_offset);

t_fractol_canvas	*set_canvas_settings(t_fractol_canvas *canvas, \
uint32_t iteration, double pixel_size, double border_thickness);

t_fractol_canvas	*set_canvas_pixels_empty(t_fractol_canvas *canvas);

int					pixel_is_empty(uint32_t *pixel);

/////////////////////////////
///////   viewport   ////////
/////////////////////////////

void				set_viewport_center(t_fractol_canvas *canvas, \
double center_real, double center_imaginary);

void				move_viewport_real(t_fractol_canvas *canvas, \
uint32_t pixel_amount, int direction);

void				move_viewport_imaginary(t_fractol_canvas *canvas, \
uint32_t pixel_amount, int direction);

////////////////////////////////
///////   translation   ////////
////////////////////////////////

int					translate_left_or_right(t_fractol_canvas *canvas, \
t_fractol_func fractal, unsigned int controls);

int					translate_up_or_down(t_fractol_canvas *canvas, \
t_fractol_func fractal, unsigned int controls);

t_fractol_canvas	*calculate_left_translation(t_fractol_canvas *canvas, \
uint32_t delta);

t_fractol_canvas	*calculate_right_translation(t_fractol_canvas *canvas, \
uint32_t delta);

t_fractol_canvas	*calculate_down_translation(t_fractol_canvas *canvas, \
uint32_t delta);

t_fractol_canvas	*calculate_up_translation(t_fractol_canvas *canvas, \
uint32_t delta);

t_fractol_canvas	*resize_canvas(t_fractol_canvas *canvas, \
int32_t width, int32_t height);

#endif