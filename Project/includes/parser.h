/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:06:50 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/05 13:24:45 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_elements
{
	sp = 0,
	pl,
	cy,
	A,
	C,
	L,
	END,
}			t_elements;

int		ft_count_lines(char **argv);
int		ft_open_file(char **argv);
char	**ft_read_and_get_file(char **argv, int total);
void	ft_parse_rt_file(t_mem *mem, char **rt_file);
int		ft_check_numb_args(char **element);
int		ft_string_to_enum(char *pick);
void	ft_pick_element(t_mem *mem, char *pick, char **elements);
void	ft_get_xyz_double(t_mem *mem, char *str, t_vec3 *aux);
void	ft_get_x_double(t_mem *mem, char *str, t_vec3 *aux);
void	ft_check_color_values(t_mem *mem, t_vec3 color);
void	ft_check_intensity_value(t_mem *mem, double intensity);
void	ft_check_normal_values(t_mem *mem, t_vec3 normal);
void	ft_check_fov_value(t_mem *mem, double fov);
void	ft_add_ambient_to_scene(t_mem *mem, char **element);
void	ft_add_camera_to_scene(t_mem *mem, char **element);
void	ft_add_light_to_scene(t_mem *mem, char **element);
void	ft_add_sphere_to_scene(t_mem *mem, char **element);
void	ft_add_plane_to_scene(t_mem *mem, char **element);
void	ft_add_cylinder_to_scene(t_mem *mem, char **element);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t len);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_free_split(char **split);
void	ft_free_valids(char **valid_str);

#endif