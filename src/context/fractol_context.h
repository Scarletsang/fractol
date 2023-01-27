/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_context.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:16:49 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 22:29:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONTEXT_H
# define FRACTOL_CONTEXT_H

# include "fractol_painter.h"

typedef struct s_fractol_context
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	t_fractol_func		fractal;
	t_fractol_complex	viewport;
	t_fractol_canvas	canvas;
}				t_fractol_context;

t_fractol_context	*init_fractal(t_fractol_context *program, \
t_fractol_func fractal, double center_real, double center_complex);

t_fractol_context	*set_viewport(t_fractol_context *program, \
double center_real, double center_imaginary);

////////////////////////////////
///////   translation   ////////
////////////////////////////////

t_fractol_context	*calculate_left_translation(t_fractol_context *program, \
uint32_t delta);

t_fractol_context	*calculate_right_translation(t_fractol_context *program, \
uint32_t delta);

t_fractol_context	*calculate_down_translation(t_fractol_context *program, \
uint32_t delta);

t_fractol_context	*calculate_up_translation(t_fractol_context *program, \
uint32_t delta);

t_fractol_context	*resize_canvas(t_fractol_context *program, \
int32_t width, int32_t height);

#endif