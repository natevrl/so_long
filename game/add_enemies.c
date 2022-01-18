/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:52:05 by v3r               #+#    #+#             */
/*   Updated: 2022/01/18 23:35:04 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	put_enemies(t_mlx *vars, int x, int y)
{
	static int	k = -1;

	vars->enemies->x[++k] = x;
	vars->enemies->y[k] = y;
	vars->maps->r_path = "./images/enemies.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->r_path,
			&vars->maps->img_width, &vars->maps->img_height);
	if (!vars->maps->img)
		return (0);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
	mlx_destroy_image(vars->mlx, vars->maps->img);
	return (1);
}
