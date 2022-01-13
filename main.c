/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/13 23:17:51 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//!!!!!!!NE PAS OUBLIER DE FREE vars->mlx A LA FIN!!!!!!!
int	main(void)
{
 //   img_data	img_s;
    t_mlx      *vars;
    t_img character;
    //_img map;


    vars = malloc(sizeof(t_mlx));
    if (vars == 0)
        return (0);
    vars->soldat = malloc(sizeof(t_img));
    vars->maps = malloc(sizeof(t_img));
    vars->walls = malloc(sizeof(t_tuple));

    //init windows
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, X_RESOLUTION, Y_RESOLUTION, "NbenhaGame");

    init_map(vars);
    printf("POS inside MAIN = %d, %d\n", vars->soldat->x, vars->soldat->y);


    //mlx_hook(vars.mlx_win, 17, 1L<<17, event_hook, (void *)0);
  	mlx_hook(vars->mlx_win, 2, 1L << 0, moove_soldat, vars);
    mlx_loop(vars->mlx);
    return (0);
}
