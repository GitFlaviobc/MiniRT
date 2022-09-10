/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:06:08 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 21:55:25 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	*ft_new_create_vector(double x, double y, double z)
{
	t_vec3	*vec;

	vec = (t_vec3 *)malloc(sizeof(t_vec3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec3	*ft_new_copy_vector(t_vec3 *copy)
{
	t_vec3	*vec;

	vec = (t_vec3 *)malloc(sizeof(t_vec3));
	vec->x = copy->x;
	vec->y = copy->y;
	vec->z = copy->z;
	return (vec);
}

t_vec3	ft_create_vector(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3	ft_copy_vector(t_vec3 copy)
{
	t_vec3	vec;

	vec.x = copy.x;
	vec.y = copy.y;
	vec.z = copy.z;
	return (vec);
}
