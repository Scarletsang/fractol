#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "fractol_complex.h"

void	test_complex_multiply(void);

void	test_complex_divide(void);

void	test_complex_pow(void);

void	test_repeated_complex_pow(void);

void	test_mandelbrot(void);

#endif