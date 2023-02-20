/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithematic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:07 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 01:27:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/complex.h"

void	complex_divide(t_fractol_complex *complex, \
double real, double imaginary)
{
	double	denominator;
	double	original_real;

	denominator = (real * real) + (imaginary * imaginary);
	original_real = complex->real;
	complex->real = ((complex->real * real) + \
		(complex->imaginary * imaginary)) / denominator;
	complex->imaginary = ((complex->imaginary * real) - \
		(original_real * imaginary)) / denominator;
}

void	complex_multiply(t_fractol_complex *complex, \
double real, double imaginary)
{
	double	original_real;

	original_real = complex->real;
	complex->real = \
		(complex->real * real) - (complex->imaginary * imaginary);
	complex->imaginary = \
		(original_real * imaginary) + (complex->imaginary * real);
}

void	complex_scalar_multiply(t_fractol_complex *complex, \
double scalar)
{
	complex->real *= scalar;
	complex->imaginary *= scalar;
}

void	complex_add(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real += real;
	complex->imaginary += imaginary;
}
