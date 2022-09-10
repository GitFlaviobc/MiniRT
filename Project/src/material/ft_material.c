/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:55:30 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 20:15:55 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	*ft_make_material(void)
{
	t_material	*mat;

	mat = (t_material *)malloc(sizeof(t_material));
	mat->color = ft_new_create_color(0.5, 0.5, 0.5);
	mat->k_ambient = 0.1;
	mat->k_diffuse = 1000;
	return (mat);
}

void	ft_set_material_color(t_material *mat, double r, double g, double b)
{
	mat->color->r = r;
	mat->color->g = g;
	mat->color->b = b;
}

void	ft_set_material_ambient(t_material *mat, double k)
{
	mat->k_ambient = k;
}

void	ft_set_material_diffuse(t_material *mat, double k)
{
	mat->k_diffuse = k;
}

void	ft_free_material(t_material *mat)
{
	free(mat->color);
	free(mat);
}
