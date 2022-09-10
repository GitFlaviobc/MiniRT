/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:13:10 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/22 19:42:22 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "minirt.h"
# include "vector.h"

typedef struct s_hit
{
	t_vec3			*p_hit;
	t_vec3			*v_normal;
	t_material		*mat;
	double			dist;
	int				count;
}	t_hit;

t_hit	*ft_create_hit(void);
void	ft_reset_hit(t_hit *hit);
void	ft_free_hit(t_hit *hit);

#endif