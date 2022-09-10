/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:46 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 13:51:31 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct s_material
{
	t_color		*color;
	double		k_ambient;
	double		k_diffuse;
}				t_material;

/*
	Creation Functions
*/
t_material	*ft_make_material(void);

/*
	Set Functions
*/
void		ft_set_material_color(t_material *mat,
				double r,
				double g,
				double b);
void		ft_set_material_ambient(t_material *mat, double k);
void		ft_set_material_diffuse(t_material *mat, double k);

/*
	Free Functions
*/
void		ft_free_material(t_material *mat);

#endif