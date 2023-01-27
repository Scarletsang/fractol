/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:01:29 by htsang            #+#    #+#             */
/*   Updated: 2023/01/27 00:52:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1920
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1024
# endif

# include <stdlib.h>
# include "fractol_painter.h"

void	fractol_key_hook(mlx_key_data_t keydata, void *hook_ctx);

void	fractol_resize_hook(int32_t width, int32_t height, void *hook_ctx);

#endif