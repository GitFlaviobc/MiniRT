/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:53 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/22 13:00:21 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	t_vec3	*v_dir;
	t_vec3	*p_ori;
	t_hit	*hit;
}	t_ray;

t_ray	*ft_create_ray(void);
void	ft_new_direction(t_camera *cam, t_ray *ray, int i, int j);
void	ft_set_ray_dir(t_ray *ray, t_vec3 *v_new_dir);
void	ft_set_ray_ori(t_ray *ray, t_vec3 *p_new_ori);
void	ft_free_ray(t_ray *ray);

#endif