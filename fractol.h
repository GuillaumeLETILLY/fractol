/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:45:38 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/12 21:29:52 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "printf/ft_printf.h"
# include <stdlib.h>

# define SIZE 600

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*addr;
	char	*name;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_iterations;
	int		color;
	double	x;
	double	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_fractal;

int		key_press(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);
int		exit_fractal(t_fractal *fractal);
int		draw_fractal(t_fractal *fractal, char *query, double cx, double cy);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	calculate_mandelbrot(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal, double cx, double cy);
void	calculate_burning_ship(t_fractal *fractal);
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
double	ft_atof(char *str);

#endif
