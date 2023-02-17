/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:53:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 18:20:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FRACTOL/fractol.h"

int	prepare_draw(t_fractol_context *program)
{
	if (is_triggered(&program->controls, CHANGE_Z))
	{
		update_cursor_pos(program);
		convert_cursor_pos_to_complex(program, &program->canvas.estimator.z);
	}
	if (is_triggered(&program->controls, COLOR_SHIFT))
	{
		shift_color(program);
	}
	if (!translate_viewport(program))
	{
		return (1);
	}
	return (0);
}

void	fractol_draw_hook(t_fractol_context *program)
{
	int	translated;

	if (!program->controls)
		return ;
	translated = prepare_draw(program);
	default_canvas_bounds(&program->canvas);
	if (is_triggered(&program->controls, ANIMATION))
		animate(program);
	else if ((program->controls <= 0b1111) && translated)
		translate(program);
	else if (program->controls == COLOR_SHIFT)
		paint_pixels_from_distance_map(&program->canvas);
	else
	{
		if (translated)
			translate_distance_map(program);
		else
			program->painter_func(\
				&program->canvas, &program->painter, program->fractal);
		default_canvas_bounds(&program->canvas);
		paint_pixels_from_distance_map(&program->canvas);
	}
	if (is_triggered(&program->controls, ZOOM))
		program->controls &= ~ZOOM;
}

void	fractol_key_hook(mlx_key_data_t keydata, t_fractol_context *program)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(program->mlx);
		return ;
	}
	if (keydata.key == MLX_KEY_LEFT)
		press_switch(&keydata.action, &program->controls, TRANSLATE_LEFT);
	if (keydata.key == MLX_KEY_RIGHT)
		press_switch(&keydata.action, &program->controls, TRANSLATE_RIGHT);
	if (keydata.key == MLX_KEY_DOWN)
		press_switch(&keydata.action, &program->controls, TRANSLATE_DOWN);
	if (keydata.key == MLX_KEY_UP)
		press_switch(&keydata.action, &program->controls, TRANSLATE_UP);
	if (keydata.key == MLX_KEY_Z)
		press_switch(&keydata.action, &program->controls, CHANGE_Z);
	if (keydata.key == MLX_KEY_S && \
		((keydata.action == MLX_PRESS) || (keydata.action == MLX_REPEAT)))
		change_animation_speed(program, keydata.modifier != MLX_SHIFT);
	if ((keydata.key == MLX_KEY_A) && (keydata.action == MLX_PRESS))
		press_animation_lever(program);
	if ((keydata.key == MLX_KEY_C) && (keydata.action == MLX_PRESS))
		press_lever(&program->controls, COLOR_SHIFT);
}

void	fractol_scroll_hook(double xdelta, double ydelta, \
t_fractol_context *program)
{
	if (ydelta)
	{
		calculate_zoom(program, ydelta);
	}
	else
	{
		calculate_zoom(program, xdelta);
	}
	update_cursor_pos(program);
	program->controls |= ZOOM;
}

void	fractol_resize_hook(int32_t width, int32_t height, \
t_fractol_context *program)
{
	if (calculate_canvas_resize(&program->canvas, width, height))
	{
		mlx_close_window(program->mlx);
		return ;
	}
	program->painter_func(&program->canvas, &program->painter, \
		program->fractal);
	paint_pixels_from_distance_map(&program->canvas);
}
