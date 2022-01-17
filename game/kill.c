/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:17 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 19:53:17 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	kill_all(t_mlx *vars)
{
	if (vars->mlx != 0)
	{
		if (vars->player->img != 0)
			mlx_destroy_image(vars->mlx, vars->player->img);
		if (vars->maps->img != 0)
			mlx_destroy_image(vars->mlx, vars->maps->img);
		if (vars->mlx_win != 0)
			mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_display(vars->mlx);
	}
	if (vars->player != 0)
		free(vars->player);
	if (vars->maps != 0)
		free(vars->maps);
	if (vars->walls->y != 0)
		free(vars->walls->y);
	if (vars->walls->x != 0)
		free(vars->walls->x);
	if (vars->walls != 0)
		free(vars->walls);
	if (vars->collectible->y != 0)
		free(vars->collectible->y);
	if (vars->collectible->x != 0)
		free(vars->collectible->x);
	if (vars->collectible != 0)
		free(vars->collectible);
	if (vars->mlx != 0)
		free(vars->mlx);
	if (vars != 0)
		free(vars);
	exit(0);
}
