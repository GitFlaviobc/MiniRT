/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:02:41 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 23:47:07 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_alloc_rt_mem(t_mem *mem)
{
	mem->img = ft_alloc_image();
	mem->ray = ft_create_ray();
	mem->canvas = new_canvas(WIDTH, HEIGHT);
	mem->objs = ft_create_obj_list();
	mem->lights = ft_create_light_list();
	mem->parser = NULL;
	mem->ambient = NULL;
	mem->cam = NULL;
	mem->mlx = NULL;
	mem->max[0] = 0;
	mem->max[1] = 0;
	mem->max[2] = 0;
}

void	ft_init_mem_mlx(t_mem *mem)
{
	mem->mlx = mlx_init();
	mem->mlx_win = mlx_new_window(mem->mlx, WIDTH, HEIGHT, "MiniRT");
	mem->img->img = mlx_new_image(mem->mlx, WIDTH, HEIGHT);
	mem->img->addr = mlx_get_data_addr(mem->img->img,
			&mem->img->bits_per_pixel,
			&mem->img->line_length,
			&mem->img->endian);
	ft_get_pixel_canvas(mem->img, mem->canvas);
	mlx_put_image_to_window(mem->mlx, mem->mlx_win, mem->img->img, 0, 0);
}

t_img	*ft_alloc_image(void)
{
	t_img	*image;

	image = (t_img *) malloc(sizeof(t_img));
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	return (image);
}
