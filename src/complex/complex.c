/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:40:16 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:53:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/complex.h"

double	complex_magnitude_square(t_fractol_complex *complex)
{
	return (complex->imaginary * complex->imaginary \
	+ complex->real * complex->real);
}

double	complex_magnitude(t_fractol_complex *complex)
{
	return (sqrt(complex->imaginary * complex->imaginary \
	+ complex->real * complex->real));
}

void	copy_complex_number(t_fractol_complex *dest, \
t_fractol_complex *src)
{
	dest->real = src->real;
	dest->imaginary = src->imaginary;
}

void	set_complex_number(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real = real;
	complex->imaginary = imaginary;
}
