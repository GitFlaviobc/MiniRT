/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:43 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 13:52:24 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

typedef struct s_light
{
	struct s_light	*next;
	struct s_light	*prev;
	t_vec3			*p_pos;
	t_color			*color;
	double			brightness;
}				t_light;

typedef struct s_light_list
{
	int		total;
	t_light	*first;
	t_light	*last;
}	t_light_list;

/*
	Creation Functions
*/
t_light_list	*ft_create_light_list(void);
t_light			*ft_create_light(void);
void			ft_add_light_to_list(t_light_list *list);

/*
	Set Functions
*/
void			ft_set_light_color(t_light *light,
					double r,
					double g,
					double b);
void			ft_set_light_position(t_light *light,
					double x,
					double y,
					double z);
void			ft_set_light_brightness(t_light *light, double brightness);

/*
	Check Functions
*/
void			ft_color_ambient_light(t_mem *mem, t_obj *obj, t_color *color);
void			ft_check_light_list(t_color *color, t_ray *ray, t_mem *mem);
void			ft_check_light(t_color *color, t_ray *ray, t_light *light);
void			ft_check_shadow(t_mem *mem, t_ray *ray);
int				ft_in_shadow(t_vec3 *p_light, t_vec3 *p_hit, t_mem *mem);

/*
	Free Functions
*/
void			ft_free_light(t_light *light);
void			ft_free_light_list(t_light_list *list);
void			ft_free_light_from_list(t_light_list *list, t_light *light);

#endif