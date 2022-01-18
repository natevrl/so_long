/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:41:03 by v3r               #+#    #+#             */
/*   Updated: 2022/01/18 22:17:22 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	malloc_tabs_of_xy(t_mlx *vars)
{
	vars->walls->x = malloc(sizeof(int) * vars->walls->max);
	if (vars->walls->x == 0)
		malloc_error(vars);
	vars->walls->y = malloc(sizeof(int) * vars->walls->max);
	if (vars->walls->y == 0)
		malloc_error(vars);
	vars->collectible->x = malloc(sizeof(int) * vars->collectible->max);
	if (vars->collectible->x == 0)
		malloc_error(vars);
	vars->collectible->y = malloc(sizeof(int) * vars->collectible->max);
	if (vars->collectible->y == 0)
		malloc_error(vars);
	vars->enemies->x = malloc(sizeof(int) * vars->enemies->max);
	if (vars->collectible->x == 0)
		malloc_error(vars);
	vars->enemies->y = malloc(sizeof(int) * vars->enemies->max);
	if (vars->collectible->y == 0)
		malloc_error(vars);
}

static void	malloc_struct(t_mlx *vars)
{
	vars->player = malloc(sizeof(t_img));
	if (vars->player == 0)
		malloc_error(vars);
	vars->maps = malloc(sizeof(t_img));
	if (vars->maps == 0)
		malloc_error(vars);
	vars->walls = malloc(sizeof(t_tuple));
	if (vars->walls == 0)
		malloc_error(vars);
	vars->collectible = malloc(sizeof(t_tuple));
	if (vars->collectible == 0)
		malloc_error(vars);
	vars->enemies = malloc(sizeof(t_tuple));
	if (vars->enemies == 0)
		malloc_error(vars);
}

static void	init_struct(t_mlx *vars)
{
	vars->is_escape = 0;
	vars->is_player = 0;
	vars->collectible->max = 0;
	vars->collectible->touched = 0;
	vars->walls->max = 0;
	vars->win_width = 0;
	vars->win_height = 0;
	vars->mlx = 0;
	vars->player->img = 0;
	vars->player->img = 0;
	vars->walls->y = 0;
	vars->walls->x = 0;
	vars->collectible->x = 0;
	vars->collectible->y = 0;
	vars->enemies->max = 0;
	vars->enemies->touched = 0;
	vars->enemies->x = 0;
	vars->enemies->y = 0;
}

void	game_driver(char *path)
{
	t_mlx	*vars;

	vars = malloc(sizeof(t_mlx));
	if (vars == 0)
		malloc_error(vars);
	malloc_struct(vars);
	init_struct(vars);
	map_parsing(vars, path);
	malloc_tabs_of_xy(vars);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, IMG_BITS * vars->win_width,
			IMG_BITS * vars->win_height, "so_long");
	map_drawer(vars, path);
	mlx_hook(vars->mlx_win, 2, 1L << 0, moove_player, vars);
	mlx_hook(vars->mlx_win, 17, 1L << 17, mlx_loop_end, vars->mlx);
	mlx_loop(vars->mlx);
	kill_all(vars);
}
