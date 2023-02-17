/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:37:02 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 15:01:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/fractol.h"
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
	write(STDERR_FILENO, "Usage:\t", 8);
	write(STDERR_FILENO, program_name, ft_strlen(program_name));
	write(STDERR_FILENO, \
		" [mandelbrot|julia|newton]\n", 28);
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
