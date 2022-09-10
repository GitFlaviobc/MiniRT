/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_float_math.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:57:16 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 00:50:19 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	ft_double_multi_vec(double nb, t_vec3 vec)
{
	t_vec3	ret;

	ret.x = vec.x * nb;
	ret.y = vec.y * nb;
	ret.z = vec.z * nb;
	return (ret);
}

t_vec3	ft_double_divide_vec(double nb, t_vec3 vec)
{
	t_vec3	ret;

	ret.x = vec.x / nb;
	ret.y = vec.y / nb;
	ret.z = vec.z / nb;
	return (ret);
}

t_vec3	*ft_new_double_multi_vec(double nb, t_vec3 vec_a)
{
	t_vec3	*vec;

	vec = (t_vec3 *)malloc(sizeof(t_vec3));
	vec->x = vec_a.x * nb;
	vec->y = vec_a.y * nb;
	vec->z = vec_a.z * nb;
	return (vec);
}

t_vec3	*ft_new_double_divide_vec(double nb, t_vec3 vec_a)
{
	t_vec3	*vec;

	vec = (t_vec3 *)malloc(sizeof(t_vec3));
	vec->x = vec_a.x / nb;
	vec->y = vec_a.y / nb;
	vec->z = vec_a.z / nb;
	return (vec);
}
