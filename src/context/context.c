/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:34 by htsang            #+#    #+#             */
/*   Updated: 2023/02/02 21:31:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

t_fractol_context	*init_fractal(t_fractol_context *program, \
t_fractol_func fractal, double viewport_real, double viewport_imaginary)
{
	program->fractal = fractal;
	set_complex_number(&program->viewport, viewport_real, viewport_imaginary);
	init_canvas(&program->canvas, &program->viewport);
	return (program);
}
