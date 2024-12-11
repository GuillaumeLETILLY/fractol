/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:15:38 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/12 18:15:55 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	if (!fractal)
		return (0);
	mouse_re = (x - SIZE / 2.0) / fractal->zoom + fractal->offset_x;
	mouse_im = (y - SIZE / 2.0) / fractal->zoom + fractal->offset_y;
	if (button == 5)
	{
		fractal->zoom *= 0.9;
		fractal->offset_x = mouse_re - (x - SIZE / 2.0) / fractal->zoom;
		fractal->offset_y = mouse_im - (y - SIZE / 2.0) / fractal->zoom;
	}
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		fractal->offset_x = mouse_re - (x - SIZE / 2.0) / fractal->zoom;
		fractal->offset_y = mouse_im - (y - SIZE / 2.0) / fractal->zoom;
	}
	draw_fractal(fractal, fractal->name, fractal->cx, fractal->cy);
	return (1);
}
