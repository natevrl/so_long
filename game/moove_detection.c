/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:46:37 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 19:38:11 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	compteur_de_pas(void)
{
	static int	i = 1;

	printf("%d\n", i);
	i++;
}

int	is_wall(t_mlx *vars, int x, int y)
{
	int	i;

	i = 0;
	while (++i < vars->walls->max)
		if (x == vars->walls->x[i] && y == vars->walls->y[i])
			return (1);
	return (0);
}

int	is_escape(t_mlx *vars, int x, int y)
{
	if (x == vars->walls->x[0] && y == vars->walls->y[0])
	{
		if (vars->collectible->nb_looted == vars->collectible->max)
		{
			compteur_de_pas();
			mlx_loop_end(vars->mlx);
		}
		else
			return (1);
	}
	return (0);
}

void	is_collectible(t_mlx *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i < vars->collectible->max)
	{
		if (x == vars->collectible->x[i] && y == vars->collectible->y[i])
		{
			vars->collectible->nb_looted++;
			vars->collectible->x[i] = 0;
			vars->collectible->y[i] = 0;
		}
		i++;
	}
}

int	ucango(t_mlx *vars, int x, int y)
{
	if (is_wall(vars, x, y))
		return (0);
	if (is_escape(vars, x, y))
		return (0);
	is_collectible(vars, x, y);
	compteur_de_pas();
	return (1);
}
