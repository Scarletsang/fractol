/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:37:02 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 17:04:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/cli.h"
#include <unistd.h>

/**
** @param str: a NULL-terminated string
** @return the length of the given string
*/
static size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

int	print_program_usage(const char *program_name)
{
	size_t	program_name_len;

	program_name_len = ft_strlen(program_name);
	write(STDERR_FILENO, "Usage:\n   ", 11);
	write(STDERR_FILENO, program_name, program_name_len);
	write(STDERR_FILENO, " mandelbrot\nor ", 16);
	write(STDERR_FILENO, program_name, program_name_len);
	write(STDERR_FILENO, " julia <z_value real> <z_value imaginary>\nor ", 46);
	write(STDERR_FILENO, program_name, program_name_len);
	write(STDERR_FILENO, " burningship <factor real> <factor imaginary>\n", 47);
	return (EXIT_FAILURE);
}

int	print_invalid_option_msg(const char *program_name, const char *fractal_name)
{
	write(STDERR_FILENO, program_name, ft_strlen(program_name));
	write(STDERR_FILENO, ": illegal argument: ", 21);
	write(STDERR_FILENO, fractal_name, ft_strlen(fractal_name));
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}
