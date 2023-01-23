/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/23 23:57:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PAINTER_H
# define FRACTOL_PAINTER_H

# include "MLX42/MLX42.h"
# include "fractol_complex.h"

typedef struct s_fractol_viewport
{
	double		real_min;
	double		real_max;
	double		imaginary_min;
	double		imaginary_max;
	double		imaginary_step;
	double		real_step;
	mlx_image_t	*canvas;
}				t_fractol_viewport;

int					draw_mandelbrot(t_fractol_viewport *viewport, \
mlx_image_t *canvas);

t_fractol_viewport	*init_mandelbrot(t_fractol_viewport *viewport);

t_fractol_viewport	*calc_steps(t_fractol_viewport *viewport, \
mlx_image_t *canvas);

#endif