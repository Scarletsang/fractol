/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:32:08 by htsang            #+#    #+#             */
/*   Updated: 2023/02/18 20:32:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/cli.h"

int	string_matches(const char *str, char *expected)
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

int	ft_isdigit(int c)
{
	return ((c > 47) && (c < 58));
}

double	ft_strtod(const char *str)
{
	double	number;
	int		sign;
	int		place;

	number = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		number = number * 10 + (*str++ - '0');
	if (*str == '.')
	{
		place = 1;
		while (ft_isdigit(*++str))
			number += (*str - '0') / (pow(10, place++));
	}
	return (number * sign);
}

int	is_valid_number(const char *str)
{
	int	check;

	check = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		check = 1;
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			check = 1;
			str++;
		}
	}
	return (check && (*str == 0));
}

int	move_parser(int *argc, const char ***argv)
{
	if ((*argc - 1) == 0)
	{
		return (EXIT_FAILURE);
	}
	(*argc)--;
	(*argv)++;
	return (EXIT_SUCCESS);
}
