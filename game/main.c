/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/15 01:37:44 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// RESTE A FAIRE :
// ---- 1 : regler le leaks des 2 bytes GNL
// ---- 2 : Gerer toutes les erreurs (errno) et proteger les mallocs
// ---- 3 : Parser la map, la rendre valide 
// ---- 4 : Norminer

int	main(int ac, char **av)
{
    t_mlx      *vars;

    if (ac != 2)
    {
        printf("Invalid number of arguments");
        return (0);
    }
    vars = init_all(av[1]);

    mlx_hook(vars->mlx_win, 17, 1L<<17, moove_player, vars);
  	mlx_hook(vars->mlx_win, 2, 1L << 0, moove_player, vars);
    mlx_loop(vars->mlx);
    return (0);
}
