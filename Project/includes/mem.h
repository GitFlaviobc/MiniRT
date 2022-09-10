/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:35:17 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 23:12:27 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "minirt.h"
/*
	MLX image Struct
*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/*
	Canvas Struct
*/
typedef struct s_canvas
{
	unsigned int	*data;
	int				width;
	int				height;
}	t_canvas;

/*
	Main memory Struct
*/
typedef struct s_mem
{
	void				*mlx;
	void				*mlx_win;
	int					max[3];
	char				**parser;
	t_canvas			*canvas;
	t_img				*img;
	struct s_camera		*cam;
	struct s_ray		*ray;
	struct s_light		*ambient;
	struct s_light_list	*lights;
	struct s_obj_list	*objs;
}	t_mem;

/*
	Main Memmory Functions
*/
void		ft_alloc_rt_mem(t_mem *mem);
void		ft_init_mem_mlx(t_mem *mem);
int			ft_end_rt(t_mem *mem, int nb_exit);

/*
	Utils Functions
*/
t_img		*ft_alloc_image(void);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *dest, int c, size_t n);

/*
	Canvas Functions
*/
t_canvas	*new_canvas(int width, int height);
void		ft_free_canvas(t_canvas *canvas);

#endif