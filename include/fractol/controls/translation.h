/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:23:15 by htsang            #+#    #+#             */
/*   Updated: 2023/02/14 16:27:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONTROLS_TRANSLATION_H
# define FRACTOL_CONTROLS_TRANSLATION_H

# include "fractol/context.h"

////////////////////////////
///////    public   ////////
////////////////////////////

int					translate(t_fractol_context *program);

int					translate_viewport(t_fractol_context *program);

void	        	copy_pixels(mlx_image_t *image, t_fractol_pixel_copier *copier);

/////////////////////////////
///////    private   ////////
/////////////////////////////

int					calculate_horizontal_translation(t_fractol_canvas *canvas, \
int32_t left_movement);	

int					calculate_vertical_translation(t_fractol_canvas *canvas, \
int32_t up_movement);
void				adjust_vertical_translation(t_fractol_canvas *canvas, \
int32_t left_movement);

t_fractol_canvas	*calculate_canvas_resize(t_fractol_canvas *canvas, \
int32_t width, int32_t height);

#endif