/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:00:31 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 22:57:28 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	malloc_error(t_mlx *vars)
{
	perror("Error\nmalloc() error");
	kill_all(vars);
}

void	invalid_map_error(t_mlx *vars)
{
	printf("Error\nInvalid map\n");
	kill_all(vars);
}

void	check_open_error(t_mlx *vars, int fd)
{
	if (fd == -1)
	{
		perror("Error\nopen() error");
		kill_all(vars);
	}
}

void	check_read_error(t_mlx *vars, int ret, char *str)
{
	if (ret == -1)
	{
		if (str)
			free(str);
		perror("Error\nread() error");
		kill_all(vars);
	}
}
