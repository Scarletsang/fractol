/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:01:29 by htsang            #+#    #+#             */
/*   Updated: 2023/01/30 00:13:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1024

# include <stdlib.h>
# include "fractol_context.h"

void	fractol_translation_hook(t_fractol_context *program);

void	fractol_key_hook(mlx_key_data_t keydata, t_fractol_context *hook_ctx);

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program);

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program);

#endif