/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:44:51 by htsang            #+#    #+#             */
/*   Updated: 2023/02/18 20:02:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# include "FRACTOL/context.h"

int		print_program_usage(const char *program_name);

int		print_invalid_option_msg(const char *program_name, \
const char *fractal_name);

int		string_matches(const char *str, char *expected);

double	ft_strtod(const char *str);

int		ft_isdigit(int c);

int		is_valid_number(const char *str);

int		move_parser(int *argc, const char ***argv);

int		parse_input(t_fractol_context *program, int argc, const char **argv);

#endif