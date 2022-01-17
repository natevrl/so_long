/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:17 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 22:26:09 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	kill_window(t_mlx *vars)
{
	if (vars->mlx)
	{
		if (vars->player->img)
			mlx_destroy_image(vars->mlx, vars->player->img);
		if (vars->maps->img)
			mlx_destroy_image(vars->mlx, vars->maps->img);
		if (vars->mlx_win)
			mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_display(vars->mlx);
	}
}

void	kill_all(t_mlx *vars)
{
	kill_window(vars);
	if (vars->player)
		free(vars->player);
	if (vars->maps)
		free(vars->maps);
	if (vars->walls->y)
		free(vars->walls->y);
	if (vars->walls->x)
		free(vars->walls->x);
	if (vars->walls)
		free(vars->walls);
	if (vars->collectible->y)
		free(vars->collectible->y);
	if (vars->collectible->x)
		free(vars->collectible->x);
	if (vars->collectible)
		free(vars->collectible);
	if (vars->mlx)
		free(vars->mlx);
	if (vars)
		free(vars);
	exit(0);
}
