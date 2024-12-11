/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:45:38 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/12 21:41:59 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

static void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit_fractal(fractal);
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fractol");
	if (!fractal->window)
		exit_fractal(fractal);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->image)
		exit_fractal(fractal);
	fractal->addr = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	fractal->zoom = 300;
	fractal->max_iterations = 200;
	fractal->color = 0x0000FF;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
}

static void	print_usage(void)
{
	ft_printf("Gros abuse fait effort > ./fractol [type] [parameters]\n");
	ft_printf("Uniquement :\n");
	ft_printf("1 : Mandelbrot\n");
	ft_printf("2 : Julia\n");
	ft_printf("3 : Burning Ship\n");
	exit(1);
}

static void	check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 4)
		print_usage();
	if (ft_strncmp(argv[1], "1", 1) != 0 && ft_strncmp(argv[1], "2", 1) != 0
		&& ft_strncmp(argv[1], "3", 1) != 0)
		print_usage();
	if (ft_strncmp(argv[1], "2", 1) == 0 && argc != 4)
		print_usage();
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	double		cx;
	double		cy;

	check_args(argc, argv);
	init_fractal(&fractal);
	cx = 0.0;
	cy = 0.0;
	if (ft_strncmp(argv[1], "1", 1) == 0)
		fractal.name = "1";
	else if (ft_strncmp(argv[1], "2", 1) == 0)
	{
		fractal.name = "2";
		cx = ft_atof(argv[2]);
		cy = ft_atof(argv[3]);
	}
	else
		fractal.name = "3";
	draw_fractal(&fractal, fractal.name, cx, cy);
	mlx_key_hook(fractal.window, key_press, &fractal);
	mlx_hook(fractal.window, 17, 0, exit_fractal, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
