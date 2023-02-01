/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_canvas.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:58:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 14:14:44 by htsang           ###   ########.fr       */
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
	t_fractol_canvas_setting	settings;
}				t_fractol_canvas;

///////////////////////////
///////   canvas   ////////
///////////////////////////

t_fractol_canvas	*set_canvas_end(t_fractol_canvas *canvas, \
uint32_t end_x, uint32_t end_y);

t_fractol_canvas	*set_canvas_start(t_fractol_canvas *canvas, \
uint32_t start_x, uint32_t start_y);

t_fractol_canvas	*set_canvas_complex_start(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, double real_offset, double imaginary_offset);

t_fractol_canvas	*set_canvas_settings(t_fractol_canvas *canvas, \
uint32_t iteration, double pixel_size, double border_thickness);

/////////////////////////////
///////   viewport   ////////
/////////////////////////////

t_fractol_canvas	*move_viewport_real(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t pixel_amount, int direction);

t_fractol_canvas	*move_viewport_imaginary(t_fractol_canvas *canvas, \
t_fractol_complex *viewport, uint32_t pixel_amount, int direction);

#endif