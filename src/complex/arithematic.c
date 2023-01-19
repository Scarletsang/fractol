/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithematic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:07 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 15:33:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

static t_fractol_complex	*complex_odd_pow(t_fractol_complex *complex, \
int power)
{
	t_fractol_complex	square;
	
	copy_complex_number(&square, complex);
	complex_pow(&square, power / 2);
	complex_multiply(&square, square.real, square.imaginary);
	return (complex_multiply(complex, square.real, square.imaginary));
}

t_fractol_complex	*complex_pow(t_fractol_complex *complex, \
int power)
{
	if (power == 1)
	{
		return (complex);
	}
	if (power % 2 == 0)
	{
		complex_pow(complex, power / 2);
		complex_multiply(complex, complex->real, complex->imaginary);
		return (complex);
	}
	return (complex_odd_pow(complex, power));
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
