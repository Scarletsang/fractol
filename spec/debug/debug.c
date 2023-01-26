/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:21:23 by htsang            #+#    #+#             */
/*   Updated: 2023/01/26 01:10:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "fractol_painter.h"

void	print_complex(t_fractol_complex *complex, char *title)
{
	printf("%-15s: %.10f%+.10fi\n", title, complex->real, complex->imaginary);
}

void	print_viewport(t_fractol_viewport *viewport)
{
	printf("================\n-----math-----\n");
	printf("%-15s: %10f\n", "real_min", viewport->math.real_min);
	printf("%-15s: %10f\n", "imaginary_max", viewport->math.imaginary_max);
	print_complex(&viewport->math.z, "z");
	print_complex(&viewport->math.c, "c");
	printf("----painter---\n");
	printf("%-15s: %10f\n", "pixel_size", viewport->painter.pixel_size);
	printf("%-15s: %10u\n", "x", viewport->painter.x);
	printf("%-15s: %10u\n", "y", viewport->painter.y);
	printf("%-15s: %10u\n", "width", viewport->painter.width);
	printf("%-15s: %10u\n", "height", viewport->painter.height);
	printf("%-15s: %10p\n", "pixels", viewport->painter.pixels);
	printf("----canvas----\n");
	printf("%-15s: %10u\n", "width", viewport->canvas->width);
	printf("%-15s: %10u\n", "height", viewport->canvas->height);
	printf("%-15s: %10p\n", "pixels", viewport->canvas->pixels);
}
