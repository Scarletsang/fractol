/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:40:16 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 01:11:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

t_fractol_complex	*copy_complex_number(t_fractol_complex *dest, \
t_fractol_complex *src)
{
	return (set_complex_number(dest, src->real, src->imaginary));
}

t_fractol_complex	*set_complex_number(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real = real;
	complex->imaginary = imaginary;
	return (complex);
}
