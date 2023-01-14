/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithematic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:07 by htsang            #+#    #+#             */
/*   Updated: 2023/01/14 20:52:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex/fractol_complex.h"

t_fractol_complex	*fractol_pow(t_fractol_complex *complex, \
double real, double imaginary)
{
	// complex->real = pow(real;
	complex->imaginary = imaginary;
	return (complex);
}

t_fractol_complex	*fractol_mutiply(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real = \
		(complex->real * real) - (complex->imaginary * imaginary);
	complex->imaginary = \
		(complex->real * imaginary) + (complex->imaginary * real);
	return (complex);
}

t_fractol_complex	*fractol_subtract(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real -= real;
	complex->imaginary -= imaginary;
	return (complex);
}

t_fractol_complex	*fractol_add(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real += real;
	complex->imaginary += imaginary;
	return (complex);
}
