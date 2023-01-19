/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_complex.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:10 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 01:13:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMPLEX_H
# define FRACTOL_COMPLEX_H

# include <stdlib.h>
# include <math.h>

typedef struct s_fractol_complex
{
	double	real;
	double	imaginary;
}               t_fractol_complex;

t_fractol_complex	*copy_complex_number(t_fractol_complex *dest, \
t_fractol_complex *src);

t_fractol_complex	*set_complex_number(t_fractol_complex *complex, \
double real, double imaginary);

t_fractol_complex	*complex_pow(t_fractol_complex *complex, \
int power);

t_fractol_complex	*complex_multiply(t_fractol_complex *complex, \
double real, double imaginary);

t_fractol_complex	*complex_subtract(t_fractol_complex *complex, \
double real, double imaginary);

t_fractol_complex	*complex_add(t_fractol_complex *complex, \
double real, double imaginary);

#endif