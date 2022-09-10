/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:29:27 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/28 00:47:55 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_uint8	ft_mini_clamp(t_uint8 check)
{
	if (check > (t_uint8)255)
		return ((t_uint8)255);
	if (check < 0)
		return (0);
	return (check);
}

int64_t	ft_set_pixel(t_color color)
{
	unsigned int	pixel;

	color.r = 255 * pow(color.r, 1 / 2.2);
	color.g = 255 * pow(color.g, 1 / 2.2);
	color.b = 255 * pow(color.b, 1 / 2.2);
	pixel = 0;
	pixel |= (ft_mini_clamp(color.r) & 0x0ff) << 16;
	pixel |= (ft_mini_clamp(color.g) & 0x0ff) << 8;
	pixel |= ft_mini_clamp(color.b) & 0x0ff;
	return (pixel);
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_get_pixel_canvas(t_img *img, t_canvas *canvas)
{
	int	x;
	int	y;

	x = 0;
	while (x <= canvas->height)
	{
		y = 0;
		while (y <= canvas->width)
		{
			ft_mlx_pixel_put(img, x, y, canvas->data[x + canvas->width * y]);
			y++;
		}
		x++;
	}
}
