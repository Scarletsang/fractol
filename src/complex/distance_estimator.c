/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_estimator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:06:04 by htsang            #+#    #+#             */
/*   Updated: 2023/02/13 21:46:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

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

t_fractol_distance	*set_distance(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator)
{
	double	magnitude;

	magnitude = sqrt(estimator->magnitude_square);
	distance->distance = log(estimator->magnitude_square) * \
				magnitude / complex_magnitude(&estimator->derivative);
	distance->potential = log(log(magnitude) / pow(2, estimator->iteration));
	return (distance);
}

t_fractol_distance	*set_constant_distance(t_fractol_distance *distance, \
int value)
{
	distance->distance = value;
	distance->potential = 0;
	return (distance);
}
