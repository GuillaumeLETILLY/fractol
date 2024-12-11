/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:15:38 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/12 18:14:05 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_color(t_fractal *fractal)
{
	static int	color_index = 0;

	color_index = (color_index + 1) % 6;
	if (color_index == 0)
		fractal->color = 0x0000FF;
	else if (color_index == 1)
		fractal->color = 0x00FF00;
	else if (color_index == 2)
		fractal->color = 0xFF0000;
	else if (color_index == 3)
		fractal->color = 0xFF00FF;
	else if (color_index == 4)
		fractal->color = 0x00FFFF;
	else if (color_index == 5)
		fractal->color = 0xFFFF00;
}

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		exit_fractal(fractal);
	if (keycode == 65361)
		fractal->offset_x -= 10 / fractal->zoom;
	if (keycode == 65363)
		fractal->offset_x += 10 / fractal->zoom;
	if (keycode == 65364)
		fractal->offset_y += 10 / fractal->zoom;
	if (keycode == 65362)
		fractal->offset_y -= 10 / fractal->zoom;
	if (keycode == 65505)
		change_color(fractal);
	draw_fractal(fractal, fractal->name, fractal->cx, fractal->cy);
	return (0);
}
