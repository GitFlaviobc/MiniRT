/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:43:33 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/13 00:08:49 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_make_rt(t_mem *mem, t_canvas *canv)
{
	int			i;
	int			j;
	t_color		color;

	color = ft_create_color(0, 0, 0);
	i = 0;
	while (i <= HEIGHT - 1)
	{
		j = 0;
		while (j <= WIDTH - 1)
		{
			ft_new_direction(mem->cam, mem->ray, i, j);
			ft_check_intersec(mem, mem->ray, &color);
			if (mem->ray->hit->count == 0)
				color = ft_create_color(0, 0, 0);
			else
				ft_check_light_list(&color, mem->ray, mem);
			canv->data[HEIGHT - 1 - i + canv->width * j] = ft_set_pixel(color);
			ft_reset_hit(mem->ray->hit);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_extension(char *file, char *rt)
{
	while (*file && *file != '.')
		file++;
	if (!ft_strcmp(file, rt))
		return ;
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, WEXT, 23);
	exit(-1);
}

int	ft_key_hook(int key, t_mem *mem)
{
	if (key == ESC)
		ft_end_rt(mem, 0);
	return (0);
}

int	ft_loop(t_mem *mem)
{
	mlx_put_image_to_window(mem->mlx, mem->mlx_win, mem->img->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mem	mem;
	int		total;

	if (argc == 2)
	{
		ft_check_extension(argv[1], ".rt");
		total = ft_count_lines(argv);
		ft_alloc_rt_mem(&mem);
		mem.parser = ft_read_and_get_file(argv, total);
		ft_parse_rt_file(&mem, mem.parser);
		ft_make_rt(&mem, mem.canvas);
		ft_init_mem_mlx(&mem);
		mlx_hook(mem.mlx_win, 17, 1L << 2, ft_end_rt, &mem);
		mlx_hook(mem.mlx_win, 2, 1L << 0, ft_key_hook, &mem);
		mlx_expose_hook(mem.mlx_win, ft_loop, &mem);
		mlx_loop(mem.mlx);
	}
	else
	{
		write(STDERR_FILENO, "Error\n", 7);
		write(STDERR_FILENO, WARGC, 33);
	}
	return (0);
}
