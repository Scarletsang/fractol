/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:15:56 by htsang            #+#    #+#             */
/*   Updated: 2023/02/06 19:26:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_painter.h"

int	pixel_is_inset(uint32_t *pixel)
{
	return (*pixel == (uint32_t) (INSET_COLOR << 24));
}

int	pixel_is_empty(uint32_t *pixel)
{
	return (*pixel == 0);
}
