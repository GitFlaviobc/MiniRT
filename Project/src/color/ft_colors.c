/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:54:40 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 21:33:48 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*ft_new_create_color(double r, double g, double b)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_color	ft_create_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	ft_copy_color(t_color copy)
{
	t_color	color;

	color.r = copy.r;
	color.g = copy.g;
	color.b = copy.b;
	return (color);
}

void	ft_clamp(t_color *color)
{
	if (color->r > 1.)
		color->r = 1.;
	else if (color->r < 0.)
		color->r = 0.;
	if (color->g > 1.)
		color->g = 1.;
	else if (color->g < 0.)
		color->g = 0.;
	if (color->b > 1.)
		color->b = 1.;
	else if (color->b < 0.)
		color->b = 0.;
}
