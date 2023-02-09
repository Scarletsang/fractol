/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_border_tracer.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:33:50 by htsang            #+#    #+#             */
/*   Updated: 2023/02/09 15:57:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BORDER_TRACER_H
# define FRACTOL_BORDER_TRACER_H

# include "fractol_painter.h"

void	turn_tracer_clockwise(t_fractol_tracer *tracer);

void	turn_tracer_anticlockwise(t_fractol_tracer *tracer);

void	flip_tracer_direction(t_fractol_tracer *tracer);

void	move_painter_backwards(t_fractol_tracer *tracer);

int		move_painter(t_fractol_canvas *canvas, t_fractol_tracer *tracer);

#endif