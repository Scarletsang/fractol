/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_estimator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:02:33 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 17:45:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

double	mandelbrot_distance_estimator(t_fractol_complex *z, \
t_fractol_complex *c, double escape_value, int iteration)
{
	t_fractol_complex	dz;
	double				z_magnitude_square;

	set_complex_number(z, 0, 0);
	set_complex_number(&dz, 0, 0);
	while (iteration > 0)
	{
		mandelbrot_equation_derivative(&dz, z);
		mandelbrot_equation(z, c);
		z_magnitude_square = complex_magnitude_square(z);
		if (z_magnitude_square > escape_value)
		{
			break;
		}
		iteration--;
	}
	return (log10(z_magnitude_square) * \
	sqrt(z_magnitude_square) / complex_magnitude(&dz));
}
