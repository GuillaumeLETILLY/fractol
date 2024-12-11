/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:15:38 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/12 21:35:59 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;
	int		color;

	fractal->name = "1";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x - SIZE / 2) / fractal->zoom + fractal->offset_x;
	fractal->cy = (fractal->y - SIZE / 2) / fractal->zoom + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= 4)
			break ;
	}
	color = ((fractal->color & 0xFF) * i / fractal->max_iterations)
		| (((fractal->color & 0xFF00) * i / fractal->max_iterations) & 0xFF00)
		| (((fractal->color & 0xFF0000) * i / fractal->max_iterations)
			& 0xFF0000);
	put_color_to_pixel(fractal, fractal->x, fractal->y, color);
}

void	calculate_julia(t_fractal *fractal, double cx, double cy)
{
	int		i;
	double	tmp;
	int		color;

	fractal->name = "2";
	fractal->cx = cx;
	fractal->cy = cy;
	fractal->zx = (fractal->x - SIZE / 2) / fractal->zoom + fractal->offset_x;
	fractal->zy = (fractal->y - SIZE / 2) / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= 4)
			break ;
	}
	color = ((fractal->color & 0xFF) * i / fractal->max_iterations)
		| (((fractal->color & 0xFF00) * i / fractal->max_iterations) & 0xFF00)
		| (((fractal->color & 0xFF0000) * i / fractal->max_iterations)
			& 0xFF0000);
	put_color_to_pixel(fractal, fractal->x, fractal->y, color);
}

int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
	if (!fractal || !query)
		return (0);
	fractal->y = -1;
	while (++fractal->y < SIZE)
	{
		fractal->x = -1;
		while (++fractal->x < SIZE)
		{
			if (query[0] == '1')
				calculate_mandelbrot(fractal);
			else if (query[0] == '2')
				calculate_julia(fractal, cx, cy);
			else if (query[0] == '3')
				calculate_burning_ship(fractal);
			else
				return (0);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (1);
}
