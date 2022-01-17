/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:40:45 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 23:52:23 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_wall(t_mlx *vars, int x, int y)
{
	static int	f = -1;

	vars->walls->x[++f] = x;
	vars->walls->y[f] = y;
	vars->maps->r_path = "./images/rock.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->r_path,
			&vars->maps->img_width, &vars->maps->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
	mlx_destroy_image(vars->mlx, vars->maps->img);
}

void	put_ground(t_mlx *vars, int x, int y)
{
	vars->maps->r_path = "./images/center.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->r_path,
			&vars->maps->img_width, &vars->maps->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
	mlx_destroy_image(vars->mlx, vars->maps->img);
}

void	put_collectible(t_mlx *vars, int x, int y)
{
	static int	k = -1;

	vars->collectible->x[++k] = x;
	vars->collectible->y[k] = y;
	vars->maps->r_path = "./images/collectible.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->r_path,
			&vars->maps->img_width, &vars->maps->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
	mlx_destroy_image(vars->mlx, vars->maps->img);
}

void	put_player(t_mlx *vars, int x, int y)
{
	vars->player->x = x;
	vars->player->y = y;
	vars->player->r_path = "./images/character.xpm";
	vars->player->img = mlx_xpm_file_to_image(vars->mlx, vars->player->r_path,
			&vars->player->img_width, &vars->player->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, x, y);
}

void	put_escape(t_mlx *vars, int x, int y)
{
	vars->walls->x[0] = x;
	vars->walls->y[0] = y;
	vars->maps->r_path = "./images/escape.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->r_path,
			&vars->maps->img_width, &vars->maps->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
	mlx_destroy_image(vars->mlx, vars->maps->img);
}
