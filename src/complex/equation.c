/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:54 by htsang            #+#    #+#             */
/*   Updated: 2023/01/23 22:19:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

t_fractol_complex	*mandelbrot_equation(t_fractol_complex *z, \
t_fractol_complex *c)
{
	complex_multiply(z, z->real, z->imaginary);
	complex_add(z, c->real, c->imaginary);
	return (z);
}

t_fractol_complex	*mandelbrot_equation_derivative(t_fractol_complex *dz, \
t_fractol_complex *z)
{
	complex_multiply(dz, z->real, z->imaginary);
	complex_multiply(dz, 2, 0);
	complex_add(dz, 1, 0);
	return (dz);
}
