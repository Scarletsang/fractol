/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:21:28 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 16:29:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_complex.h"

t_fractol_complex	*mandelbrot_dynamic(t_fractol_complex *z, \
t_fractol_complex *c, double escape_value, int iteration)
{
	set_complex_number(z, 0, 0);
	while (iteration > 0 && z->real <= escape_value)
	{
		mandelbrot_equation(z, c);
		iteration--;
	}
	return (z);
}