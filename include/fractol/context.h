/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:16:49 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 19:26:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONTEXT_H
# define FRACTOL_CONTEXT_H

# include "FRACTOL/painter.h"

typedef enum e_fractol_control
{
	TRANSLATE_LEFT = 0b1,
	TRANSLATE_RIGHT = 0b10,
	TRANSLATE_DOWN = 0b100,
	TRANSLATE_UP = 0b1000,
	ZOOM = 0b10000,
	CHANGE_Z = 0b100000,
	ANIMATION = 0b1000000
}				t_fractol_control;

typedef struct s_fractol_context
{
	mlx_t					*mlx;
	t_fractol_func			fractal;
	t_fractol_painter_func	painter_func;
	t_fractol_canvas		canvas;
	t_fractol_painter		painter;
	unsigned int			controls;
	int32_t					mouse_x;
	int32_t					mouse_y;
	const char				*program_name;
}				t_fractol_context;

t_fractol_context	*init_fractal(t_fractol_context *program, \
t_fractol_func fractal, double center_real, double center_complex);

////////////////////////////////
///////     Controls     ///////
////////////////////////////////

void				press_switch(action_t *key_action, unsigned int *controls, \
t_fractol_control control);

int					is_triggered(unsigned int *controls, \
t_fractol_control control);

int					press_lever(unsigned int *controls, \
t_fractol_control control);

void				convert_cursor_pos_to_complex(t_fractol_context *program, \
t_fractol_complex *dest);

bool				update_cursor_pos(t_fractol_context *program);

////////////////////////////////
///////       zoom       ///////
////////////////////////////////

t_fractol_context	*calculate_zoom(t_fractol_context *program, double ydelta);

#endif