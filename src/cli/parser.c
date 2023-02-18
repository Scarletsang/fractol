/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:43:46 by htsang            #+#    #+#             */
/*   Updated: 2023/02/18 20:58:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/cli.h"

static int	parse_z_values(t_fractol_context *program, int argc, \
const char **argv)
{
	t_fractol_complex	estimator_z;

	if (move_parser(&argc, &argv))
	{
		set_complex_number(&program->canvas.estimator.z, -0.73, 0.18);
		return (--argc);
	}
	if (!is_valid_number(*argv))
		return (argc);
	estimator_z.real = ft_strtod(*argv);
	if (move_parser(&argc, &argv))
		return (argc);
	if (!is_valid_number(*argv))
		return (argc);
	estimator_z.imaginary = ft_strtod(*argv);
	copy_complex_number(&program->canvas.estimator.z, &estimator_z);
	return (--argc);
}

int	parse_input(t_fractol_context *program, int argc, const char **argv)
{
	if (move_parser(&argc, &argv))
	{
		return (1);
	}
	if (string_matches(*argv, "mandelbrot"))
	{
		program->fractal = &mandelbrot_fractal_func;
		argc--;
	}
	else if (string_matches(*argv, "newton"))
	{
		program->fractal = &newton_fractal_func;
		argc = parse_z_values(program, argc, argv);
	}
	else if (string_matches(*argv, "julia"))
	{
		program->fractal = &julia_fractal_func;
		argc = parse_z_values(program, argc, argv);
	}
	return (argc);
}
