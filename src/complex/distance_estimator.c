/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_estimator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:02:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/01 15:59:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

double	mandelbrot_distance_estimator(t_fractol_complex *z, \
t_fractol_complex *c, double border_size, int iteration)
{
	t_fractol_complex	dz;
	double				z_magnitude_square;

	copy_complex_number(z, c);
	set_complex_number(&dz, 1, 0);
	while (iteration > 0)
	{
		z_magnitude_square = complex_magnitude_square(z);
		if (z_magnitude_square < fractal_border(&dz, border_size))
		{
			return (BORDER_VALUE);
		}
		if (z_magnitude_square > 100)
		{
			return (log(z_magnitude_square) * \
				sqrt(z_magnitude_square) / complex_magnitude(&dz));
		}
		mandelbrot_equation_derivative(&dz, z, 1);
		mandelbrot_equation(z, c);
		iteration--;
	}
	return (INSET_VALUE);
}

double	julia_distance_estimator(t_fractol_complex *c, \
t_fractol_complex *original_z, double border_size, int iteration)
{
	t_fractol_complex	dz;
	t_fractol_complex	z;
	double				z_magnitude_square;

	copy_complex_number(&z, original_z);
	set_complex_number(&dz, 1, 0);
	while (iteration > 0)
	{
		z_magnitude_square = complex_magnitude_square(&z);
		if (z_magnitude_square < fractal_border(&dz, border_size))
		{
			return (BORDER_VALUE);
		}
		if (z_magnitude_square > 100)
		{
			return (log(z_magnitude_square) * \
				sqrt(z_magnitude_square) / complex_magnitude(&dz));
		}
		mandelbrot_equation_derivative(&dz, &z, 1);
		mandelbrot_equation(&z, c);
		iteration--;
	}
	return (INSET_VALUE);
}
