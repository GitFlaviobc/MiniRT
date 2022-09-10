/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:27:21 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 13:51:48 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef enum e_obj_types
{
	SPHERE = 0,
	PLANE,
	CYLINDER,
}			t_obj_types;

typedef struct s_obj
{
	struct s_obj	*next;
	struct s_obj	*prev;
	int				id;
	int				type;
	t_material		*mat;
	t_vec3			*p_center;
	double			radius;
	t_vec3			*v_normal;
	double			height;
	int				shad;
}	t_obj;

typedef struct s_obj_list
{
	int		total;
	t_obj	*first;
	t_obj	*last;
}	t_obj_list;

/*
	Creation Functions
*/
t_obj		*ft_create_obj(int type);
t_obj_list	*ft_create_obj_list(void);
void		ft_add_obj_to_list(int type, t_obj_list *list);

/*
	Intersection Functions
*/
void		ft_check_intersec(t_mem *mem, t_ray *ray, t_color *color);
void		ft_pick_intersect_type(t_obj *obj, t_ray *ray);
void		ft_sphere_check(t_obj *sphere, t_ray *ray, t_hit *hit);
void		ft_cylinder_check(t_obj *cylinder, t_ray *ray, t_hit *hit);
void		ft_plane_check(t_obj *plane, t_ray *ray, t_hit *hit);

/*
	Set Functions
*/
void		ft_obj_set_center(t_obj *obj, double x, double y, double z);
void		ft_obj_set_radius(t_obj *obj, double radius);
void		ft_obj_set_normal(t_obj *obj, double x, double y, double z);
void		ft_obj_set_height(t_obj *obj, double height);

/*
	Free Functions
*/
void		ft_free_obj_list(t_obj_list *list);
void		ft_free_obj(t_obj_list *list, t_obj *obj);
void		ft_free_obj_by_type(t_obj *obj);
void		ft_free_sphere(t_obj *sphere);
void		ft_free_plane(t_obj *plane);
void		ft_free_cylinder(t_obj *cylinder);

/*
	Utils Intersect Functions
*/
void		ft_get_hit_point(t_ray *ray, t_hit *hit);
int			ft_is_in_front(double last_hit, double root);
void		ft_is_set_hit(t_hit *hit, t_obj *obj, double dist);
int			ft_check_height_hit(double dist, double height, double root);

#endif