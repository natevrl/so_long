/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:00:31 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 19:33:31 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	malloc_error(t_mlx *vars)
{
	perror("malloc() error");
	kill_all(vars);
}

void	invalid_map_error(t_mlx *vars)
{
	printf("Invalid map\n");
	kill_all(vars);
}

void	check_open_error(t_mlx *vars, int fd)
{
	if (fd == -1)
	{
		perror("open() error");
		kill_all(vars);
	}
}

void	check_read_error(t_mlx *vars, int ret)
{
	if (ret == -1)
	{
		perror("read() error");
		kill_all(vars);
	}
}
