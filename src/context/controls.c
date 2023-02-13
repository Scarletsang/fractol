/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:41:40 by htsang            #+#    #+#             */
/*   Updated: 2023/02/13 21:33:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_context.h"

void	convert_cursor_pos_to_complex(t_fractol_context *program, \
t_fractol_complex *dest)
{
	set_complex_number(dest, \
		program->canvas.viewport.real + \
			(program->mouse_x * program->canvas.pixel_size), \
		program->canvas.viewport.imaginary - \
			(program->mouse_y * program->canvas.pixel_size));
}

bool	update_cursor_pos(t_fractol_context *program)
{
	int32_t	old_mouse_x;
	int32_t	old_mouse_y;

	old_mouse_x = program->mouse_x;
	old_mouse_y = program->mouse_y;
	mlx_get_mouse_pos(program->mlx, &program->mouse_x, &program->mouse_y);
	return (((old_mouse_x - program->mouse_x) == 0) && \
		((old_mouse_y - program->mouse_y) == 0));
}

void	press_switch(action_t *key_action, unsigned int *controls, \
t_fractol_control control)
{
	if (*key_action == MLX_PRESS || *key_action == MLX_REPEAT)
		*controls |= control;
	if (*key_action == MLX_RELEASE)
		*controls &= ~control;
}

int	press_lever(unsigned int *controls, t_fractol_control control)
{
	if ((*controls & control) == control)
	{
		*controls &= ~control;
		return (1);
	}
	else
	{
		*controls |= control;
		return (0);
	}
}

int	is_triggered(unsigned int *controls, t_fractol_control control)
{
	return ((*controls & control) == control);
}
