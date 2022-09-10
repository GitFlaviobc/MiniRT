/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:52:47 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/27 13:58:01 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	ft_add_vec(t_vec3 vec_a, t_vec3 vec_b)
{
	t_vec3	vec;

	vec.x = vec_a.x + vec_b.x;
	vec.y = vec_a.y + vec_b.y;
	vec.z = vec_a.z + vec_b.z;
	return (vec);
}

t_vec3	ft_minus_vec(t_vec3 vec_a, t_vec3 vec_b)
{
	t_vec3	vec;

	vec.x = vec_a.x - vec_b.x;
	vec.y = vec_a.y - vec_b.y;
	vec.z = vec_a.z - vec_b.z;
	return (vec);
}

t_vec3	ft_multi_vec(t_vec3 vec_a, t_vec3 vec_b)
{
	t_vec3	vec;

	vec.x = vec_a.x * vec_b.x;
	vec.y = vec_a.y * vec_b.y;
	vec.z = vec_a.z * vec_b.z;
	return (vec);
}

t_vec3	ft_divide_vec(t_vec3 vec_a, t_vec3 vec_b)
{
	t_vec3	vec;

	vec.x = vec_a.x / vec_b.x;
	vec.y = vec_a.y / vec_b.y;
	vec.z = vec_a.z / vec_b.z;
	return (vec);
}
