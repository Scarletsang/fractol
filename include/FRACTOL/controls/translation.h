/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:23:15 by htsang            #+#    #+#             */
/*   Updated: 2023/02/17 18:13:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATION_H
# define TRANSLATION_H

# include "FRACTOL/context.h"

typedef void	(*t_fractol_copier_func)(void *dest, void *src);

typedef struct s_fractol_copier
{
	void	*dest;
	void	*src;
	int32_t	up_movement;
	int32_t	left_movement;
}				t_fractol_copier;

////////////////////////////
///////    public   ////////
////////////////////////////

void				translate(t_fractol_context *program);

void				translate_distance_map(t_fractol_context *program);

int					translate_viewport(t_fractol_context *program);

void				copy_pixels(t_fractol_canvas *canvas, \
t_fractol_copier *copier);

void				copy_distance_points(t_fractol_canvas *canvas, \
t_fractol_copier *copier);

/////////////////////////////
///////    private   ////////
/////////////////////////////

int					horizontal_translate_canvas_bounds(\
t_fractol_canvas *canvas, int32_t left_movement);	

int					vertical_translate_canvas_bounds(t_fractol_canvas *canvas, \
int32_t up_movement);
void				adjust_vertical_translation(t_fractol_canvas *canvas, \
int32_t left_movement);

#endif