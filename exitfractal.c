/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitfractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:57 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/12 18:15:30 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_fractal *fractal)
{
	if (fractal->image != NULL)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window != NULL)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx != NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
}
