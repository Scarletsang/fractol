/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_tracer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:33:50 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 20:00:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PAINTER_BORDER_TRACER_H
# define FRACTOL_PAINTER_BORDER_TRACER_H

# include "FRACTOL/painter.h"

void	turn_tracer_clockwise(t_fractol_tracer *tracer);

void	turn_tracer_anticlockwise(t_fractol_tracer *tracer);

void	flip_tracer_direction(t_fractol_tracer *tracer);

void	move_tracer_backwards(t_fractol_tracer *tracer);

int		move_tracer(t_fractol_canvas *canvas, t_fractol_tracer *tracer);

#endif