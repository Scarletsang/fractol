/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:01:29 by htsang            #+#    #+#             */
/*   Updated: 2023/02/13 19:04:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 760

# include <stdlib.h>
# include "fractol_context.h"

typedef void	(*t_mlx_loop_func)(void *param);

int		init_fractal_from_cli(t_fractol_context *program, \
int argc, const char **argv);

void	fractol_translation_hook(t_fractol_context *program);

void	fractol_key_hook(mlx_key_data_t keydata, t_fractol_context *hook_ctx);

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program);

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program);

int		print_program_usage(const char *program_name);

int		print_invalid_option_msg(const char *program_name, \
const char *fractal_name);

int		print_unsupported_scroll_msg(const char *program_name);

#endif