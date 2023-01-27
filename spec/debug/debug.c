/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:21:23 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 20:44:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_complex(t_fractol_complex *complex, char *title)
{
	printf("%-15s: %.10f%+.10fi\n", title, complex->real, complex->imaginary);
}

void	print_viewport(t_fractol_canvas *viewport)
{
	printf("================\n-----math-----\n");
	printf("%-15s: %10f\n", "real_min", viewport->top_left_corner.real);
	printf("%-15s: %10f\n", "imaginary_max", viewport->top_left_corner.imaginary);
	print_complex(&viewport->z, "z");
	print_complex(&viewport->c, "c");
	printf("----painter---\n");
	printf("%-15s: %10f\n", "pixel_size", viewport->pixel_size);
	printf("%-15s: %10u\n", "x", viewport->x);
	printf("%-15s: %10u\n", "y", viewport->y);
	printf("%-15s: %10u\n", "width", viewport->width);
	printf("%-15s: %10u\n", "height", viewport->height);
	printf("%-15s: %10p\n", "pixels", viewport->pixels);
	printf("----canvas----\n");
	printf("%-15s: %10u\n", "width", viewport->canvas->width);
	printf("%-15s: %10u\n", "height", viewport->canvas->height);
	printf("%-15s: %10p\n", "pixels", viewport->canvas->pixels);
}
