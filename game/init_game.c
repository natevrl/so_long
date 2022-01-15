/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:41:03 by v3r               #+#    #+#             */
/*   Updated: 2022/01/15 01:32:45 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//penser a proteger tout les mallocs
void    init_tuples_walls(t_mlx *vars)
{
    vars->walls->x = malloc(sizeof(int) * vars->walls->max);
    if (vars->walls->x == 0)
        return ;
    vars->walls->y = malloc(sizeof(int) * vars->walls->max);
    if (vars->walls->y == 0)
        return ;
}

void    init_tuples_collecibles(t_mlx *vars)
{
    vars->collectible->x = malloc(sizeof(int) * vars->collectible->max);
    if (vars->collectible->x == 0)
        return ;
    vars->collectible->y = malloc(sizeof(int) * vars->collectible->max);
    if (vars->collectible->y == 0)
        return ;
}

t_mlx   *init_all(char *path)
{
    t_mlx *vars;
    
    vars = malloc(sizeof(t_mlx));
    if (vars == 0)
        return (NULL);
    vars->player = malloc(sizeof(t_img));
    vars->maps = malloc(sizeof(t_img));
    vars->walls = malloc(sizeof(t_tuple));
    vars->collectible = malloc(sizeof(t_tuple));
    if (!vars->walls || !vars->player || !vars->maps || !vars->collectible)
        return (NULL);
    vars->collectible->max = 0;
    vars->collectible->nb_looted = 0;
    vars->walls->max = 0;
    vars->win_width = 0;
    vars->win_height = 0;
    map_parsing(vars, path);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, IMG_BITS * vars->win_width, IMG_BITS * vars->win_height, "NbenhaGame");
    init_tuples_walls(vars);
    init_tuples_collecibles(vars);
    init_map(vars, path);
    return (vars);
}
