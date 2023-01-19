/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:40:16 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 15:54:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

t_fractol_complex	*copy_complex_number(t_fractol_complex *dest, \
t_fractol_complex *src)
{
	dest->real = src->real;
	dest->imaginary = src->imaginary;
	return (dest);
}

t_fractol_complex	*set_complex_number(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real = real;
	complex->imaginary = imaginary;
	return (complex);
}
