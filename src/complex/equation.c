/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:54 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 16:53:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/complex.h"

double	fractal_border(t_fractol_complex *complex, double border_size)
{
	return ((complex->imaginary * complex->imaginary * border_size) \
	+ (complex->real * complex->real * border_size));
}

void	mandelbrot_equation(t_fractol_complex *z, t_fractol_complex *c)
{
	complex_multiply(z, z->real, z->imaginary);
	complex_add(z, c->real, c->imaginary);
}

void	mandelbrot_equation_derivative(t_fractol_complex *dz, \
t_fractol_complex *z, double dc)
{
	complex_multiply(dz, z->real, z->imaginary);
	complex_multiply(dz, 2, 0);
	complex_add(dz, dc, 0);
}

void	burningship_equation(t_fractol_complex *c, \
t_fractol_complex *original_c, t_fractol_complex *factor)
{
	t_fractol_complex	temp;

	copy_complex_number(&temp, c);
	c->real = (temp.real * temp.real) - (temp.imaginary * temp.imaginary) \
		+ factor->real;
	c->imaginary = 2.0 * fabs(temp.real * temp.imaginary) + factor->imaginary;
	complex_add(c, original_c->real, original_c->imaginary);
}

void	burningship_distance_equation(t_fractol_complex *dz, \
t_fractol_complex *z)
{
	complex_add(dz, \
		log(fabs(z->real)) - log(2.0), \
		log(fabs(z->imaginary)) - log(2.0));
}
