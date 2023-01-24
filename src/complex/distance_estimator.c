/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_estimator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:02:33 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 22:52:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

double	mandelbrot_distance_estimator(t_fractol_complex *z, \
t_fractol_complex *c, double border_size, int iteration)
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
		if (z_magnitude_square < mandelbrot_border(&dz, border_size))
		{
			return (BORDER_VALUE);
		}
		if (z_magnitude_square > 4)
		{
			return (log(z_magnitude_square) * \
				sqrt(z_magnitude_square) / complex_magnitude(&dz));
		}
		iteration--;
	}
	return (INSET_VALUE);
}
