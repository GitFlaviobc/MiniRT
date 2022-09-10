/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:25:06 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 14:03:00 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*ft_create_ray(void)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	ray->p_ori = ft_new_create_vector(0, 0, 0);
	ray->v_dir = ft_normal_vector(0, 0, 0);
	ray->hit = ft_create_hit();
	return (ray);
}

void	ft_set_ray_dir(t_ray *ray, t_vec3 *v_new_dir)
{
	ray->v_dir->x = v_new_dir->x;
	ray->v_dir->y = v_new_dir->y;
	ray->v_dir->z = v_new_dir->z;
}

void	ft_set_ray_ori(t_ray *ray, t_vec3 *p_new_ori)
{
	ray->p_ori->x = p_new_ori->x;
	ray->p_ori->y = p_new_ori->y;
	ray->p_ori->z = p_new_ori->z;
}

void	ft_free_ray(t_ray *ray)
{
	free(ray->p_ori);
	free(ray->v_dir);
	ft_free_hit(ray->hit);
	free(ray);
}
