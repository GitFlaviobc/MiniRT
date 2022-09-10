/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:11:39 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/30 12:16:50 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_parser(char **parser)
{
	int	i;

	i = 0;
	while (parser[i][0] != '\0')
	{
		free(parser[i]);
		i++;
	}
	free(parser[i]);
	free(parser);
}

void	ft_destroy_mlx(t_mem *mem)
{
	mlx_destroy_image(mem->mlx, mem->img->img);
	mlx_destroy_window(mem->mlx, mem->mlx_win);
	mlx_destroy_display(mem->mlx);
	free(mem->img);
	free(mem->mlx);
}

int	ft_end_rt(t_mem *mem, int nb_exit)
{
	ft_free_ray(mem->ray);
	if (mem->cam != NULL)
		ft_free_camera(mem->cam);
	if (mem->ambient != NULL)
		ft_free_light(mem->ambient);
	ft_free_canvas(mem->canvas);
	ft_free_obj_list(mem->objs);
	ft_free_light_list(mem->lights);
	ft_free_parser(mem->parser);
	if (mem->img && mem->mlx)
		ft_destroy_mlx(mem);
	exit(nb_exit);
}
