/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:47:17 by v3r               #+#    #+#             */
/*   Updated: 2022/01/14 22:47:31 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    kill_all(t_mlx *vars)
{
    mlx_destroy_image(vars->mlx, vars->player->img);
    mlx_destroy_image(vars->mlx, vars->maps->img);
    mlx_destroy_window(vars->mlx, vars->mlx_win);
    mlx_destroy_display(vars->mlx);
    free(vars->player);
    free(vars->maps);
    free(vars->walls->y);
    free(vars->walls->x);
    free(vars->walls);
    free(vars->collectible->y);
    free(vars->collectible->x);
    free(vars->collectible);
    free(vars->mlx);
    free(vars);
    exit(0);
}