/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithematic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:07 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 01:22:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

t_fractol_complex	*complex_pow(t_fractol_complex *complex, \
int power)
{
	t_fractol_complex	square;

	if (power == 1)
	{
		return (complex);
	}
	copy_complex_number(&square, complex);
	complex_pow(&square, power / 2);
	complex_multiply(&square, square.real, square.imaginary);
	if (power % 2 == 0)
	{
		return (copy_complex_number(complex, &square));
	}
	return (complex_multiply(complex, square.real, square.imaginary));
}

t_fractol_complex	*complex_multiply(t_fractol_complex *complex, \
double real, double imaginary)
{
	double	original_real;

	original_real = complex->real;
	complex->real = \
		(complex->real * real) - (complex->imaginary * imaginary);
	complex->imaginary = \
		(original_real * imaginary) + (complex->imaginary * real);
	return (complex);
}

t_fractol_complex	*complex_subtract(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real -= real;
	complex->imaginary -= imaginary;
	return (complex);
}

t_fractol_complex	*complex_add(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real += real;
	complex->imaginary += imaginary;
	return (complex);
}
