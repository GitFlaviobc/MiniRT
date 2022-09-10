/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:04:39 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 23:42:12 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_valid_double(char *string)
{
	int		dot;
	int		i;

	dot = 0;
	i = 0;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i] != '\0')
	{
		if (!ft_isdigit(string[i]) && string[i] != '.')
			return (0);
		if (string[i] == '.')
			dot++;
		i++;
	}
	if (dot > 1)
		return (0);
	return (1);
}

double	ft_get_value(char *string)
{
	double	fraction;
	double	value;

	value = 0;
	while (ft_isdigit(*string) && *string != '\0')
		value = 10.0 * value + (*(string++) - '0');
	if (*string == '.')
	{
		string++;
		fraction = 0.1;
		while (ft_isdigit(*string) && *string != '\0')
		{
			value += (*string - '0') * fraction;
			fraction *= 0.1;
			string++;
		}
	}
	return (value);
}

double	ft_rt_atof(t_mem *mem, char *string)
{
	double	value;
	int		sign;

	while (*string == ' ')
		string++;
	if (!ft_valid_double(string))
		ft_error_parse(mem, EDOUBLE);
	sign = 1;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	value = ft_get_value(string);
	value *= sign;
	return (value);
}

void	ft_get_xyz_double(t_mem *mem, char *str, t_vec3 *aux)
{
	char	**split;
	int		total;

	split = ft_split(str, ',');
	total = 0;
	while (split[total])
		total++;
	if (total != 3)
	{
		ft_free_split(split);
		ft_error_parse(mem, EVECTOR);
	}
	aux->x = ft_rt_atof(mem, split[0]);
	aux->y = ft_rt_atof(mem, split[1]);
	aux->z = ft_rt_atof(mem, split[2]);
	ft_free_split(split);
}

void	ft_get_x_double(t_mem *mem, char *str, t_vec3 *aux)
{
	aux->x = ft_rt_atof(mem, str);
}
