/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:40:16 by htsang            #+#    #+#             */
/*   Updated: 2023/01/14 20:44:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex/fractol_complex.h"

t_fractol_complex	*create_complex_number(t_fractol_complex *complex, \
double real, double imaginary)
{
	complex->real = real;
	complex->imaginary = imaginary;
	return (complex);
}
