/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_complex.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:41:10 by htsang            #+#    #+#             */
/*   Updated: 2023/01/14 20:37:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMPLEX_H
# define FRACTOL_COMPLEX_H

# include <stdlib.h>
# include <math.h>

typedef struct s_fractol_complex
{
	double	real;
	double	imaginary;
}               t_fractol_complex;

#endif