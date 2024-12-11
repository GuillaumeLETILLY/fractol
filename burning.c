/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:35:30 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/12 21:40:44 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_burning_ship_color(t_fractal *fractal, int i)
{
	int	color;

	color = ((fractal->color & 0xFF) * i / fractal->max_iterations)
		| (((fractal->color & 0xFF00) * i / fractal->max_iterations) & 0xFF00)
		| (((fractal->color & 0xFF0000) * i / fractal->max_iterations)
			& 0xFF0000);
	return (color);
}

static void	init_burning_ship(t_fractal *fractal)
{
	fractal->name = "3";
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x - SIZE / 2) / fractal->zoom + fractal->offset_x;
	fractal->cy = (fractal->y - SIZE / 2) / fractal->zoom + fractal->offset_y;
}

static double	get_sign_value(double value)
{
	if (value < 0)
		return (-1);
	return (1);
}

void	calculate_burning_ship(t_fractal *fractal)
{
	int		i;
	double	x_temp;
	int		color;

	i = 0;
	init_burning_ship(fractal);
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = get_sign_value(fractal->zy) * 2.0
			* fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = get_sign_value(x_temp) * x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4)
			break ;
	}
	color = get_burning_ship_color(fractal, i);
	put_color_to_pixel(fractal, fractal->x, fractal->y, color);
}
