/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithematic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:07 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:53:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/complex.h"

static void	complex_odd_pow(t_fractol_complex *complex, \
int power)
{
	t_fractol_complex	square;

	copy_complex_number(&square, complex);
	complex_pow(&square, power / 2);
	complex_multiply(&square, square.real, square.imaginary);
	complex_multiply(complex, square.real, square.imaginary);
}

void	complex_pow(t_fractol_complex *complex, \
int power)
{
	if (power == 1)
	{
		return ;
	}
	if (power % 2 == 0)
	{
		complex_pow(complex, power / 2);
		complex_multiply(complex, complex->real, complex->imaginary);
		return ;
	}
	complex_odd_pow(complex, power);
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
