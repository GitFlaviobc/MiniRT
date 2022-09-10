/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:44:27 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/30 13:48:39 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "mem.h"
# include "errcode.h"
# include "vector.h"
# include "camera.h"
# include "color.h"
# include "material.h"
# include "hit.h"
# include "ray.h"
# include "object.h"
# include "light.h"
# include "gnl.h"
# include "parser.h"

# define WIDTH 800
# define HEIGHT 450
# define MAX_OBJ 3
# define TOTAL_ELEMENTS 7
# define BUFFER_SIZE 128
# define ESC 65307
# define EPSILON 0.000001

typedef void			(*t_funct)();
typedef unsigned char	t_uint8;

#endif