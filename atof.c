/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:15:38 by gletilly          #+#    #+#             */
/*   Updated: 2024/11/11 20:45:39 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	process_decimal(char *str, int i)
{
	double	decimal;
	double	div;

	decimal = 0.0;
	div = 10.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal = decimal + (str[i] - '0') / div;
		div *= 10;
		i++;
	}
	return (decimal);
}

double	ft_atof(char *str)
{
	int		i;
	double	result;
	int		sign;

	i = 0;
	result = 0.0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result += process_decimal(str, i + 1);
	return (sign * result);
}
