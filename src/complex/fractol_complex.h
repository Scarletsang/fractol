/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_complex.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:10 by htsang            #+#    #+#             */
/*   Updated: 2023/02/10 16:27:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMPLEX_H
# define FRACTOL_COMPLEX_H

# include <stdlib.h>
# include <math.h>

# ifndef INSET_VALUE
#  define INSET_VALUE 600
# endif

# ifndef BORDER_VALUE
#  define BORDER_VALUE 700
# endif

typedef struct s_fractol_complex
{
	double	real;
	double	imaginary;
}				t_fractol_complex;

typedef double	(*t_fractol_func)(t_fractol_complex *constant, \
t_fractol_complex *variable, double border_size, int iteration);

////////////////////////////////////
///////   Basic interface   ////////
////////////////////////////////////

void				copy_complex_number(t_fractol_complex *dest, \
t_fractol_complex *src);

void				set_complex_number(t_fractol_complex *complex, \
double real, double imaginary);

double				complex_magnitude(t_fractol_complex *complex);

double				complex_magnitude_square(t_fractol_complex *complex);

////////////////////////////////////////
///////   Complex Arithematic   ////////
////////////////////////////////////////

void				complex_pow(t_fractol_complex *complex, \
int power);

void				complex_multiply(t_fractol_complex *complex, \
double real, double imaginary);

void				complex_scalar_multiply(t_fractol_complex *complex, \
double scalar);

void				complex_add(t_fractol_complex *complex, \
double real, double imaginary);

////////////////////////////////////////
///////        Equations        ////////
////////////////////////////////////////

void				mandelbrot_equation(t_fractol_complex *z, \
t_fractol_complex *c);

void				mandelbrot_equation_derivative(t_fractol_complex *dz, \
t_fractol_complex *z, double dc);

double				fractal_border(t_fractol_complex *complex, \
double border_size);

double				mandelbrot_distance_estimator(t_fractol_complex *z, \
t_fractol_complex *c, double border_size, int iteration);

double				julia_distance_estimator(t_fractol_complex *c, \
t_fractol_complex *original_z, double border_size, int iteration);

double				newton_distance_estimator(t_fractol_complex *z, \
t_fractol_complex *c, double border_size, int iteration);

void				newton_equation(t_fractol_complex *z, t_fractol_complex *c);

void				newton_equation_derivative(t_fractol_complex *dz, \
t_fractol_complex *z, double dc);

#endif