/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:10 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 15:11:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <stdlib.h>
# include <math.h>

# ifndef INSET_VALUE
#  define INSET_VALUE 600
# endif

# ifndef BORDER_VALUE
#  define BORDER_VALUE 700
# endif

# ifndef EMPTY_VALUE
#  define EMPTY_VALUE 800
# endif

typedef struct s_fractol_complex
{
	double	real;
	double	imaginary;
}				t_fractol_complex;

typedef struct s_fractol_distance_estimator
{
	t_fractol_complex	z;
	t_fractol_complex	c;
	t_fractol_complex	derivative;
	double				magnitude_square;
	double				border_size;
	int					iteration;
}				t_fractol_distance_estimator;

typedef struct s_fractol_distance
{
	double	distance;
	double	potential;
}				t_fractol_distance;

typedef void	(*t_fractol_func)(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator);

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

double				fractal_border(t_fractol_complex *complex, \
double border_size);

void				mandelbrot_equation(t_fractol_complex *z, \
t_fractol_complex *c);

void				mandelbrot_equation_derivative(t_fractol_complex *dz, \
t_fractol_complex *z, double dc);

void				newton_equation(t_fractol_complex *z, t_fractol_complex *c);

void				newton_equation_derivative(t_fractol_complex *dz, \
t_fractol_complex *z, double dc);

///////////////////////////////////////////////
///////        Fractal function        ////////
///////////////////////////////////////////////

void				newton_fractal_func(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator);

void				mandelbrot_fractal_func(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator);

void				julia_fractal_func(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator);

/////////////////////////////////////////////////
///////        Distance estimator        ////////
/////////////////////////////////////////////////

void				set_distance_estimator_zc(\
t_fractol_distance_estimator *estimator, \
t_fractol_complex *z, t_fractol_complex *c);

void				set_distance_estimator_settings(\
t_fractol_distance_estimator *estimator, double border_size, int iteration);

t_fractol_distance	*set_distance(t_fractol_distance *distance, \
t_fractol_distance_estimator *estimator, int iteration);

t_fractol_distance	*set_constant_distance(t_fractol_distance *distance, \
int value);

#endif