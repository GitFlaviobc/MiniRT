/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:56 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 13:50:58 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/*
	Creation Functions
*/
t_vec3	ft_create_vector(double x, double y, double z);
t_vec3	*ft_new_create_vector(double x, double y, double z);
t_vec3	*ft_new_copy_vector(t_vec3 *copy);
t_vec3	ft_copy_vector(t_vec3 copy);

/*
	Vector Math - Functions
*/
t_vec3	*ft_vector_cross(t_vec3 *vec_a, t_vec3 *vec_b);
t_vec3	*ft_normal_vector(double x, double y, double z);
double	ft_vector_dot(t_vec3 vec_a, t_vec3 vec_b);
void	ft_normalize_vector(t_vec3 *vec);
double	ft_vector_lenght(t_vec3 vec);

/*
	Math - Vector Vector - creation Functions
*/
t_vec3	*ft_new_add_vec(t_vec3 vec_a, t_vec3 vec_b);
t_vec3	*ft_new_minus_vec(t_vec3 vec_a, t_vec3 vec_b);
t_vec3	*ft_new_multi_vec(t_vec3 vec_a, t_vec3 vec_b);
t_vec3	*ft_new_divide_vec(t_vec3 vec_a, t_vec3 vec_b);

/*
	Math - Double Vector - creation Functions
*/
t_vec3	*ft_new_double_multi_vec(double nb, t_vec3 vec_a);
t_vec3	*ft_new_double_divide_vec(double nb, t_vec3 vec_a);

/*
	Math - Vector Vector - set Functions
*/
t_vec3	ft_add_vec(t_vec3 vec_a, t_vec3 vec_b);
t_vec3	ft_minus_vec(t_vec3 vec_a, t_vec3 vec_b);
t_vec3	ft_multi_vec(t_vec3 vec_a, t_vec3 vec_b);
t_vec3	ft_divide_vec(t_vec3 vec_a, t_vec3 vec_b);

/*
	Math - Double Vector - set Functions
*/
t_vec3	ft_double_multi_vec(double nb, t_vec3 vec);
t_vec3	ft_double_divide_vec(double nb, t_vec3 vec);

#endif