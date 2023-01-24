/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_painter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:19 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 23:53:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PAINTER_H
# define FRACTOL_PAINTER_H

# include "MLX42/MLX42.h"
# include "limits.h"
# include "fractol_complex.h"

# ifndef BORDER_THICKNESS
#  define BORDER_THICKNESS 0.01
# endif

typedef struct s_fractol_viewport
{
	double		real_min;
	double		imaginary_max;
	double		step;
	mlx_image_t	*canvas;
}				t_fractol_viewport;

int					draw_mandelbrot(t_fractol_viewport *viewport);

t_fractol_viewport	*init_mandelbrot(t_fractol_viewport *viewport, \
mlx_image_t *canvas);

uint32_t			distance_to_color(double value);

#endif