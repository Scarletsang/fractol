/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:28:53 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:30:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONTROLS_ANIMATION_H
# define FRACTOL_CONTROLS_ANIMATION_H

# include "fractol/context.h"

/////////////////////////////////////////
//////    Animation Controller    ///////
/////////////////////////////////////////

void		press_animation_lever(t_fractol_context *program);

void		control_animation(t_fractol_context *program);

void		change_animation_speed(t_fractol_context *program, int increase);


///////////////////////////////////
///////      animation      ///////
///////////////////////////////////

int			animate_fractal(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

int			init_animate_fractal(t_fractol_canvas *canvas, \
t_fractol_painter *painter, t_fractol_func fractal);

void		init_animation(t_fractol_canvas *canvas, \
t_fractol_painter *painter);

#endif