/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_open_read.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:41:15 by fbonini-          #+#    #+#             */
/*   Updated: 2022/05/07 21:46:19 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_open_file(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "Error\n", 7);
		write(STDERR_FILENO, WFILE, 13);
		exit(-1);
	}
	return (fd);
}

int	ft_count_lines(char **argv)
{
	char	*read_line;
	int		total;
	int		reading;
	int		fd;

	total = 0;
	reading = 1;
	fd = ft_open_file(argv);
	while (reading == 1)
	{
		reading = get_next_line(fd, &read_line);
		free(read_line);
		total++;
	}
	close(fd);
	return (total);
}

char	**ft_read_and_get_file(char **argv, int total)
{
	char	**print;
	char	*read_line;
	int		reading;
	int		fd;
	int		i;

	fd = ft_open_file(argv);
	print = (char **)malloc(sizeof(char *) * total);
	reading = 1;
	i = 0;
	while (reading == 1)
	{
		reading = get_next_line(fd, &read_line);
		if (read_line[0] != '\0' && read_line[0] != '#')
		{
			print[i] = ft_strdup(read_line);
			i++;
		}
		free(read_line);
	}
	print[i] = ft_strdup("\0");
	close(fd);
	return (print);
}
