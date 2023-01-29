/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_context.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:16:49 by htsang            #+#    #+#             */
/*   Updated: 2023/01/29 22:38:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONTEXT_H
# define FRACTOL_CONTEXT_H

# include "fractol_painter.h"

typedef enum e_fractol_control
{
	TRANSLATE_LEFT = 0b1,
	TRANSLATE_RIGHT = 0b10,
	TRANSLATE_DOWN = 0b100,
	TRANSLATE_UP = 0b1000
}				t_fractol_control;

typedef struct s_fractol_context
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	t_fractol_func		fractal;
	t_fractol_complex	viewport;
	t_fractol_canvas	canvas;
	unsigned int		controls;
}				t_fractol_context;

t_fractol_context	*init_fractal(t_fractol_context *program, \
t_fractol_func fractal, double center_real, double center_complex);

t_fractol_context	*set_viewport_center(t_fractol_context *program, \
double center_real, double center_imaginary);

void				set_controls(action_t *key_action, unsigned int *controls, \
t_fractol_control control);

////////////////////////////////
///////   translation   ////////
////////////////////////////////

void				translate_left_or_right(unsigned int arrow_keys, \
t_fractol_context *program);

void				translate_up_or_down(unsigned int arrow_keys, \
t_fractol_context *program);

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

////////////////////////////////
///////       zoom       ///////
////////////////////////////////

void				zoom(t_fractol_context *program, double ydelta);

#endif