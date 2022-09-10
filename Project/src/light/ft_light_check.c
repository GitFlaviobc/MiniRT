/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:53:34 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 21:52:36 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_color_ambient_light(t_mem *mem, t_obj *obj, t_color *color)
{
	t_color	tmp;

	tmp = ft_copy_color(*mem->ambient->color);
	tmp = ft_double_multi_color(mem->ambient->brightness, tmp);
	tmp = ft_double_multi_color(obj->mat->k_ambient, tmp);
	tmp = ft_multi_color(tmp, *obj->mat->color);
	*color = ft_copy_color(tmp);
	ft_clamp(color);
}

double	ft_light_intensity(t_light *light, t_ray *ray)
{
	t_vec3	v_light;
	double	intensity;
	double	size;
	double	dot;

	v_light = ft_minus_vec(*light->p_pos, *ray->hit->p_hit);
	size = ft_vector_dot(v_light, v_light);
	ft_normalize_vector(&v_light);
	dot = ft_vector_dot(v_light, *ray->hit->v_normal);
	if (dot > 0)
	{
		intensity = light->brightness * ray->hit->mat->k_diffuse * dot;
		intensity = intensity / (4 * M_PI * size);
		return (intensity);
	}
	return (0);
}

void	ft_check_light(t_color *color, t_ray *ray, t_light *light)
{
	t_color	diffuse;
	double	intensity;

	intensity = ft_light_intensity(light, ray);
	diffuse = ft_copy_color(*ray->hit->mat->color);
	diffuse = ft_double_multi_color(intensity, diffuse);
	diffuse = ft_multi_color(diffuse, *light->color);
	*color = ft_add_color(*color, diffuse);
	ft_clamp(color);
}

void	ft_check_light_list(t_color *color, t_ray *ray, t_mem *mem)
{
	t_light	*light;
	int		total;

	total = 0;
	light = mem->lights->first;
	while (total < mem->lights->total)
	{
		if (!ft_in_shadow(light->p_pos, ray->hit->p_hit, mem))
			ft_check_light(color, ray, light);
		light = light->next;
		total++;
	}
}
