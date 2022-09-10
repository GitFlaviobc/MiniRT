/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:00:12 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 14:08:00 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_vector_lenght(t_vec3 vec)
{
	double	lenght;

	lenght = sqrt(ft_vector_dot(vec, vec));
	return (lenght);
}

void	ft_normalize_vector(t_vec3 *vec)
{
	double	lenght;

	lenght = ft_vector_lenght(*vec);
	*vec = ft_double_divide_vec(lenght, *vec);
}

t_vec3	*ft_normal_vector(double x, double y, double z)
{
	double	lenght;
	t_vec3	*normal;

	normal = ft_new_create_vector(x, y, z);
	lenght = ft_vector_lenght(*normal);
	*normal = ft_double_divide_vec(lenght, *normal);
	return (normal);
}
