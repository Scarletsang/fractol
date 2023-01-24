/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:01:29 by htsang            #+#    #+#             */
/*   Updated: 2023/01/24 22:00:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1024
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1024
# endif

# include <stdlib.h>
# include "MLX42/MLX42.h"

# include "fractol_painter.h"

void	fractol_key_hook(mlx_key_data_t keydata, void* viewport);

#endif