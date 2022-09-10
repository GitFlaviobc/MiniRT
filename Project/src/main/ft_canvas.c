/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:35:32 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/09 18:09:57 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*new_canvas(int width, int height)
{
	t_canvas	*canvas;
	int			size;

	canvas = malloc(sizeof(t_canvas));
	size = sizeof(canvas->data) * width * height;
	canvas->data = malloc(size);
	ft_bzero(canvas->data, size);
	canvas->width = width;
	canvas->height = height;
	return (canvas);
}

void	ft_free_canvas(t_canvas *canvas)
{
	free(canvas->data);
	free(canvas);
}
