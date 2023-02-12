/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_canvas.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:58:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/12 23:40:58 by htsang           ###   ########.fr       */
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

t_fractol_canvas	*set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y);

t_fractol_canvas	*set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y);

t_fractol_canvas	*set_canvas_settings(t_fractol_canvas *canvas, \
uint32_t iteration, double border_thickness);

t_fractol_canvas	*set_canvas_pixels_empty(t_fractol_canvas *canvas);

int					pixel_is_empty(uint32_t *pixel);

/////////////////////////////
///////   viewport   ////////
/////////////////////////////

void				move_viewport_real(t_fractol_canvas *canvas, \
int32_t pixel_amount);

void				move_viewport_imaginary(t_fractol_canvas *canvas, \
int32_t pixel_amount);

////////////////////////////////
///////   translation   ////////
////////////////////////////////

int					calculate_horizontal_translation(t_fractol_canvas *canvas, \
int32_t left_movement);	

int					calculate_vertical_translation(t_fractol_canvas *canvas, \
int32_t up_movement);
void				adjust_vertical_translation(t_fractol_canvas *canvas, \
int32_t left_movement);

t_fractol_canvas	*calculate_canvas_resize(t_fractol_canvas *canvas, \
int32_t width, int32_t height);

#endif