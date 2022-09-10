/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:23:21 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 13:59:13 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	*ft_create_hit(void)
{
	t_hit	*hit;

	hit = (t_hit *)malloc(sizeof(t_hit));
	hit->p_hit = ft_new_create_vector(0, 0, 0);
	hit->v_normal = ft_new_create_vector(0, 0, 0);
	hit->mat = NULL;
	hit->dist = 0;
	hit->count = 0;
	return (hit);
}

void	ft_reset_hit(t_hit *hit)
{
	ft_double_multi_vec(0, *hit->p_hit);
	ft_double_multi_vec(0, *hit->v_normal);
	hit->dist = 0;
	hit->count = 0;
}

void	ft_free_hit(t_hit *hit)
{
	free(hit->p_hit);
	free(hit->v_normal);
	free(hit);
}
