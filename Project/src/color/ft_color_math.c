/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:33:26 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 21:34:17 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_double_multi_color(double nb, t_color c_a)
{
	t_color	color;

	color.r = c_a.r * nb;
	color.g = c_a.g * nb;
	color.b = c_a.b * nb;
	return (color);
}

t_color	ft_add_color(t_color c_a, t_color c_b)
{
	t_color	color;

	color.r = c_a.r + c_b.r;
	color.g = c_a.g + c_b.g;
	color.b = c_a.b + c_b.b;
	return (color);
}

t_color	ft_multi_color(t_color c_a, t_color c_b)
{
	t_color	color;

	color.r = c_a.r * c_b.r;
	color.g = c_a.g * c_b.g;
	color.b = c_a.b * c_b.b;
	return (color);
}
