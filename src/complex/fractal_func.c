/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:02:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 00:11:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/complex.h"

void	newton_fractal_func(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator)
{
	int					iteration;

	set_complex_number(&estimator->derivative, 1, 0);
	iteration = 0;
	while (iteration < estimator->iteration)
	{
		estimator->magnitude_square = complex_magnitude_square(&estimator->c);
		if (estimator->magnitude_square < \
			fractal_border(&estimator->derivative, estimator->border_size))
		{
			set_constant_distance(distance, BORDER_VALUE);
			return ;
		}
		if (estimator->magnitude_square > 1000000)
		{
			set_distance(distance, estimator, iteration);
			return ;
		}
		newton_equation_derivative(&estimator->derivative, &estimator->c, 1);
		newton_equation(&estimator->c, &estimator->z);
		iteration++;
	}
	set_constant_distance(distance, INSET_VALUE);
}

void	mandelbrot_fractal_func(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator)
{
	int	iteration;

	copy_complex_number(&estimator->z, &estimator->c);
	set_complex_number(&estimator->derivative, 1, 0);
	iteration = 0;
	while (iteration < estimator->iteration)
	{
		estimator->magnitude_square = complex_magnitude_square(&estimator->z);
		if (estimator->magnitude_square < \
			fractal_border(&estimator->derivative, estimator->border_size))
		{
			set_constant_distance(distance, BORDER_VALUE);
			return ;
		}
		if (estimator->magnitude_square > 1000000)
		{
			set_distance(distance, estimator, iteration);
			return ;
		}
		mandelbrot_equation_derivative(&estimator->derivative, &estimator->z, 1);
		mandelbrot_equation(&estimator->z, &estimator->c);
		iteration++;
	}
	set_constant_distance(distance, INSET_VALUE);
}

void	julia_fractal_func(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator)
{
	int					iteration;

	set_complex_number(&estimator->derivative, 1, 0);
	iteration = 0;
	while (iteration < estimator->iteration)
	{
		estimator->magnitude_square = complex_magnitude_square(&estimator->c);
		if (estimator->magnitude_square < \
			fractal_border(&estimator->derivative, estimator->border_size))
		{
			set_constant_distance(distance, BORDER_VALUE);
			return ;
		}
		if (estimator->magnitude_square > 1000000)
		{
			set_distance(distance, estimator, iteration);
			return ;
		}
		mandelbrot_equation_derivative(&estimator->derivative, &estimator->c, 1);
		mandelbrot_equation(&estimator->c, &estimator->z);
		iteration++;
	}
	set_constant_distance(distance, INSET_VALUE);
}
