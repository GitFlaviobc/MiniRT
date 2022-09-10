/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:37 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/03 22:47:59 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "minirt.h"
# include "vector.h"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	*ft_new_create_color(double r, double g, double b);
t_color	ft_create_color(double r, double g, double b);
t_color	ft_copy_color(t_color copy);
t_color	ft_double_multi_color(double nb, t_color c_a);
t_color	ft_add_color(t_color c_a, t_color c_b);
t_color	ft_multi_color(t_color c_a, t_color c_b);
void	ft_clamp(t_color *color);

/*
	Pixel Functions
*/
int64_t	ft_set_pixel(t_color color);
void	ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_get_pixel_canvas(t_img *img, t_canvas *canvas);

#endif