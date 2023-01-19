/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:47:55 by htsang            #+#    #+#             */
/*   Updated: 2023/01/19 16:09:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*fractal;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	fractal = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	draw_fractal(fractal);
	mlx_image_to_window(mlx, fractal, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
