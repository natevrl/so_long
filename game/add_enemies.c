/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:52:05 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 23:52:17 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_enemies(t_mlx *vars, int x, int y)
{
	static int	k = -1;

	vars->enemies->x[++k] = x;
	vars->enemies->y[k] = y;
	vars->maps->r_path = "./images/enemies.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->r_path,
			&vars->maps->img_width, &vars->maps->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
	mlx_destroy_image(vars->mlx, vars->maps->img);
}
