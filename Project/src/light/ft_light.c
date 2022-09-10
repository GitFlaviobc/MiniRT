/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:06:46 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/05 13:20:12 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*ft_create_light(void)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	light->color = ft_new_create_color(1, 1, 1);
	light->p_pos = ft_new_create_vector(0, 0, 0);
	light->brightness = 0;
	return (light);
}

void	ft_set_light_color(t_light *light, double r, double g, double b)
{
	light->color->r = r;
	light->color->g = g;
	light->color->b = b;
}

void	ft_set_light_position(t_light *light, double x, double y, double z)
{
	light->p_pos->x = x;
	light->p_pos->y = y;
	light->p_pos->z = z;
}

void	ft_set_light_brightness(t_light *light, double brightness)
{
	light->brightness = brightness;
}

void	ft_free_light(t_light *light)
{
	free(light->color);
	free(light->p_pos);
	free(light);
}
