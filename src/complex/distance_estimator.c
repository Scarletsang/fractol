/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_estimator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:06:04 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 15:35:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/complex.h"

void	set_distance_estimator_zc(t_fractol_distance_estimator *estimator, \
t_fractol_complex *z, t_fractol_complex *c)
{
	estimator->z = *z;
	estimator->c = *c;
}

void	set_distance_estimator_settings(\
t_fractol_distance_estimator *estimator, double border_size, int iteration)
{
	estimator->border_size = border_size;
	estimator->iteration = iteration;
}

void	calculate_potential(t_fractol_distance *distance_point)
{
	distance_point->potential *= sqrt(sqrt(distance_point->distance));
}

t_fractol_distance	*set_distance(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator, int iteration)
{
	double	magnitude;

	magnitude = sqrt(estimator->magnitude_square);
	distance->distance = log(estimator->magnitude_square) * \
				magnitude / complex_magnitude(&estimator->derivative);
	distance->potential = log(log(magnitude) / pow(2, iteration));
	calculate_potential(distance);
	return (distance);
}

t_fractol_distance	*set_constant_distance(t_fractol_distance *distance, \
int value)
{
	distance->distance = value;
	distance->potential = 0;
	return (distance);
}
