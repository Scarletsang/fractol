/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:01:29 by htsang            #+#    #+#             */
/*   Updated: 2023/02/16 20:17:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 760

# include "FRACTOL/context.h"
# include "FRACTOL/controls/translation.h"
# include "FRACTOL/controls/animation.h"
// # include "FRACTOL/controls/color_shift.h"

typedef void	(*t_mlx_loop_func)(void *param);

int		init_fractal_from_cli(t_fractol_context *program, \
int argc, const char **argv);

void	fractol_draw_hook(t_fractol_context *program);

void	fractol_key_hook(mlx_key_data_t keydata, t_fractol_context *hook_ctx);

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program);

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program);

int		print_program_usage(const char *program_name);

int		print_invalid_option_msg(const char *program_name, \
const char *fractal_name);

#endif