/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/14 15:52:16 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main(int ac, char **av)
{
 //   img_data	img_s;
    t_mlx      *vars;
    t_img character;
    //_img map;

    if (ac != 2)
    {
        printf("Invalid number of arguments");
        return (0);
    }
    vars = malloc(sizeof(t_mlx));
    if (vars == 0)
        return (0);
    vars->soldat = malloc(sizeof(t_img));
    vars->maps = malloc(sizeof(t_img));
    vars->walls = malloc(sizeof(t_tuple));
    vars->collectible = malloc(sizeof(t_tuple));
    number_of(vars, av[1]);
    

    //init windows
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, IMG_BITS * vars->win_width, IMG_BITS * vars->win_height, "NbenhaGame");

    init_map(vars, av[1]);
    // printf("POS inside MAIN = %d, %d\n", vars->soldat->x, vars->soldat->y);


    mlx_hook(vars->mlx_win, 17, 1L<<17, moove_soldat, (void *)0);
  	mlx_hook(vars->mlx_win, 2, 1L << 0, moove_soldat, vars);
    mlx_loop(vars->mlx);
    return (0);
}
