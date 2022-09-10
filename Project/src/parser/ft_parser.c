/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:58:56 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/30 12:41:03 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_necessary_elements(t_mem *mem)
{
	if (mem->max[0] == 0)
		ft_error_parse(mem, ENAMBIENT);
	if (mem->max[1] == 0)
		ft_error_parse(mem, ENCAMERA);
	if (mem->max[2] == 0)
		ft_error_parse(mem, ENLIGHT);
}

int	ft_string_to_enum(char *pick)
{
	char	*valid_str[TOTAL_ELEMENTS];
	int		i;

	valid_str[sp] = ft_strdup("sp");
	valid_str[pl] = ft_strdup("pl");
	valid_str[cy] = ft_strdup("cy");
	valid_str[A] = ft_strdup("A");
	valid_str[C] = ft_strdup("C");
	valid_str[L] = ft_strdup("L");
	valid_str[END] = NULL;
	i = 0;
	while (valid_str[i])
	{
		if (ft_strcmp(valid_str[i], pick) == 0)
			break ;
		i++;
	}
	ft_free_valids(valid_str);
	return (i);
}

void	ft_pick_element(t_mem *mem, char *pick, char **elements)
{
	t_funct	function[TOTAL_ELEMENTS];
	int		index;

	index = ft_string_to_enum(pick);
	if (index == END)
	{
		ft_free_split(elements);
		ft_error_parse(mem, WELEMENT);
	}
	function[sp] = ft_add_sphere_to_scene;
	function[pl] = ft_add_plane_to_scene;
	function[cy] = ft_add_cylinder_to_scene;
	function[A] = ft_add_ambient_to_scene;
	function[C] = ft_add_camera_to_scene;
	function[L] = ft_add_light_to_scene;
	function[END] = ft_error_parse;
	function[index](mem, elements);
}

void	ft_parse_rt_file(t_mem *mem, char **rt_file)
{
	char	**split;
	int		i;

	i = 0;
	while (rt_file[i][0] != '\0')
	{
		split = ft_split(rt_file[i], ' ');
		ft_pick_element(mem, split[0], split);
		ft_free_split(split);
		i++;
	}
	ft_check_necessary_elements(mem);
}
