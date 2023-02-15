/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copier_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:39:26 by htsang            #+#    #+#             */
/*   Updated: 2023/02/15 23:56:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/controls/translation.h"

void	copy_pixel(uint32_t *dest, uint32_t *src)
{
	*dest = *src;
}

void	copy_distance_point(t_fractol_distance *dest, t_fractol_distance *src)
{
	*dest = *src;
}
