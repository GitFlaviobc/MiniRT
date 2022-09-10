/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_dot_cross.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:55:29 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 21:55:37 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_vector_dot(t_vec3 vec_a, t_vec3 vec_b)
{
	double	x;
	double	y;
	double	z;

	x = vec_a.x * vec_b.x;
	y = vec_a.y * vec_b.y;
	z = vec_a.z * vec_b.z;
	return (x + y + z);
}

t_vec3	*ft_vector_cross(t_vec3 *vec_a, t_vec3 *vec_b)
{
	t_vec3	*cross_vec;
	double	x;
	double	y;
	double	z;

	x = (vec_a->y * vec_b->z) - (vec_a->z * vec_b->y);
	y = (vec_a->z * vec_b->x) - (vec_a->x * vec_b->z);
	z = (vec_a->x * vec_b->y) - (vec_a->y * vec_b->x);
	cross_vec = ft_new_create_vector(x, y, z);
	return (cross_vec);
}
