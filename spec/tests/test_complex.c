/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:26:02 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 16:33:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_complex_multiply(void)
{
	t_fractol_complex	complex;

	set_complex_number(&complex, 1, 3.4);
	complex_multiply(&complex, 2.1, 4);
	printf("%f %f\n", complex.real, complex.imaginary);
}

void	test_complex_pow(void)
{
	t_fractol_complex	complex;

	set_complex_number(&complex, 1.6, 3.4);
	complex_pow(&complex, 5);
	printf("%f %f\n", complex.real, complex.imaginary);
}

void	test_repeated_complex_pow(void)
{
	int					i;
	t_fractol_complex	z;
	double				c_real;
	double				c_imaginery;

	c_real = -2;
	while (c_real < 1)
	{
		c_imaginery = 1;
		while (c_imaginery > -1)
		{
			i = 0;
			set_complex_number(&z, 0, 0);
			printf("%f %f\n", c_real, c_imaginery);
			while (i < 1000 && z.real < 2)
			{
				complex_pow(&z, 2);
				complex_add(&z, c_real, c_imaginery);
				// printf("%f %f\n", z.real, z.imaginary);
				i++;
			}
			c_imaginery -= 0.01;
		}
		c_real += 0.01;
	}
}

void	test_repeated_complex_pow_v2(void)
{
	int					i;
	t_fractol_complex	z;
	t_fractol_complex	c;

	c.real = -2;
	while (c.real < 1)
	{
		c.imaginary = 1;
		while (c.imaginary > -1)
		{
			i = 0;
			printf("%f %f\n", c.real, c.imaginary);
			mandelbrot_dynamic(&z, &c, 2, 1000);
			c.imaginary -= 0.01;
		}
		c.real += 0.01;
	}
}
