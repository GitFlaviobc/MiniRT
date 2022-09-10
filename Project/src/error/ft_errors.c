/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:06:00 by fbonini-          #+#    #+#             */
/*   Updated: 2022/04/29 23:18:12 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

void	ft_error_parse(t_mem *mem, char *msg)
{
	write(STDERR_FILENO, "Error\n", 7);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_end_rt(mem, -1);
}
