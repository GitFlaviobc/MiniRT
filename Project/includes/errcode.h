/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:36:33 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/05 13:05:29 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRCODE_H
# define ERRCODE_H

# include <errno.h>

# define WFILE "Invalid file\n"
# define WEXT "Invalid file extension\n"
# define WARGC "Number of arguments has to be 2\n"
# define WELEMENT "Invalid element\n"
# define EDOUBLE "Invalid double number\n"
# define ENCAMERA "Number of cameras (C) in the scene has to be 1\n"
# define ECAMERA "Invalid arguments for camera (C)\n"
# define ENAMBIENT "Number of ambient light (A) in the scene has to be 1\n"
# define EAMBIENT "Invalid arguments for ambient light (A)\n"
# define ENLIGHT "Number of lights (L) in the scene has to be 1\n"
# define ELIGHT "Invalid arguments for light (L)\n"
# define EPLANE "Invalid number of arguments for plane (pl)\n"
# define ECYLINDER "Invalid number of arguments for cylinder (cy)\n"
# define ESPHERE "Invalid number of arguments for sphere (sp)\n"
# define EVECTOR "Invalid format of vector (x, y, z)\n"
# define ECOLORVALUE "Color value has to be between 0 and 255\n"
# define EINTENVALUE "Light Intensisity value has to be between 0 and 1\n"
# define EFOVVALUE "FOV value has to be between 0 and 180\n"
# define ENORMALVALUE "Normal value has to be between -1 and 1\n"

void	ft_error_parse(t_mem *mem, char *msg);
void	ft_putstr_fd(char *s, int fd);

#endif