/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_limits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:59 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/05 13:16:57 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_color_values(t_mem *mem, t_vec3 color)
{
	if (color.x > 255 || color.x < 0)
		ft_error_parse(mem, ECOLORVALUE);
	if (color.y > 255 || color.y < 0)
		ft_error_parse(mem, ECOLORVALUE);
	if (color.z > 255 || color.z < 0)
		ft_error_parse(mem, ECOLORVALUE);
}

void	ft_check_intensity_value(t_mem *mem, double intensity)
{
	if (intensity > 1 || intensity < 0)
		ft_error_parse(mem, EINTENVALUE);
}

void	ft_check_normal_values(t_mem *mem, t_vec3 normal)
{
	if (normal.x > 1 || normal.x < -1)
		ft_error_parse(mem, ENORMALVALUE);
	if (normal.y > 1 || normal.y < -1)
		ft_error_parse(mem, ENORMALVALUE);
	if (normal.z > 1 || normal.z < -1)
		ft_error_parse(mem, ENORMALVALUE);
}

void	ft_check_fov_value(t_mem *mem, double fov)
{
	if (fov > 180 || fov < 0)
		ft_error_parse(mem, EFOVVALUE);
}
