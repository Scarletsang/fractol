/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_context.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:16:49 by htsang            #+#    #+#             */
/*   Updated: 2023/01/28 13:09:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONTEXT_H
# define FRACTOL_CONTEXT_H

# include "fractol_painter.h"

# define KEY_LEFT_PRESS 
# define KEY_LEFT_RELEASE 0b1110
# define KEY_RIGHT_PRESS 0b0010
# define KEY_RIGHT_RELEASE 0b1101
# define KEY_DOWN_PRESS 0b0100
# define KEY_DOWN_RELEASE 0b1011
# define KEY_UP_PRESS 0b1000
# define KEY_UP_RELEASE 0b0111

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

t_fractol_context	*set_viewport(t_fractol_context *program, \
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