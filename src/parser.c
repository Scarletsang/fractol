/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:32:08 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 22:39:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/fractol.h"

static int	string_matches(const char *str, char *expected)
{
	while (*str && *expected)
	{
		if (*str != *expected)
		{
			return (0);
		}
		str++;
		expected++;
	}
	if (*str || *expected)
	{
		return (0);
	}
	return (1);
}

double	ft_strtod(char *str)
{
	
}

int	is_number(char *str)
{
	
}

int	move_parser(int *argc, char ***argv)
{
	if ((argc - 1) == 0)
	{
		return (EXIT_FAILURE);
	}
	*argc--;
	*argv++;
	return (EXIT_SUCCESS);
}

static int	parse_julia_param(t_fractol_context *program, int argc, \
char **argv)
{
	t_fractol_complex	estimator_z;

	if (move_parser(&argc, &argv) && is_number(*argv))
	{
		return (EXIT_FAILURE);
	}
	estimator_z.real = ft_strtod(*argv);
	if (move_parser(&argc, &argv) && is_number(*argv))
	{
		return (EXIT_FAILURE);
	}
	estimator_z.imaginary = ft_strtod(*argv);
	copy_complex_number(&program->canvas.estimator.z, &estimator_z);
	return (EXIT_SUCCESS);
}

int	parse_input(t_fractol_context *program, int argc, char **argv)
{
	if (move_parser(&argc, &argv))
		return (EXIT_FAILURE);
	if (name_matches(*argv, "mandelbrot"))
		program->fractal = &mandelbrot_fractal_func;
	else if (name_matches(*argv, "newton"))
		program->fractal = &newton_fractal_func;
	else if (name_matches(*argv, "julia"))
	{
		program->fractal = &julia_fractal_func;
		if (parse_julia_param(program, argc, argv))
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
