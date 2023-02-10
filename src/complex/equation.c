/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:54 by htsang            #+#    #+#             */
/*   Updated: 2023/02/10 16:27:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

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

void	newton_equation(t_fractol_complex *z, t_fractol_complex *c)
{
	complex_multiply(z, z->real, z->imaginary);
	complex_multiply(z, z->real, z->imaginary);
	complex_add(z, -c->real, -c->imaginary);
}

void	newton_equation_derivative(t_fractol_complex *dz, \
t_fractol_complex *z, double dc)
{
	complex_multiply(dz, z->real, z->imaginary);
	complex_multiply(dz, 3, 0);
	complex_add(dz, -dc, 0);
}
