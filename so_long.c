/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/14 17:35:31 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Sutilise avec NotionNotify (track la souris en x, y)
int	mouse_move(int x, int y, t_mlx *vars)
{
   printf("%d, %d\n", x, y);
}

// S'utilise avec ButtonPress ou ButtonRelease (affiche la position x y lors du click)
int	mouse_position(int keycode, int x, int y)
{
        if (keycode == 1 && x == 1904 && y == 10)
            printf("%d, %d\n", x, y);
        else
            printf("%d\n", keycode);
        return (0);
}


// int	closett(int keycode, t_mlx vars)
// {
// 	if (keycode == 65307)
//         mlx_destroy_window(vars->mlx, vars->mlx_win);
// 	return (0);
// }

// void    init_vars(t_mlx *vars)
// {
    
//     vars = malloc(sizeof(t_mlx));
// }





void    kill_all(t_mlx *vars)
{

        mlx_destroy_image(vars->mlx, vars->soldat->img);
        mlx_destroy_image(vars->mlx, vars->maps->img);
        mlx_destroy_window(vars->mlx, vars->mlx_win);
        mlx_destroy_display(vars->mlx);
        free(vars->soldat);
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

int is_obstacle(t_mlx *vars, int x, int y)
{
    int i = 0;
    static int recup = 0;

    if (x == vars->walls->x[0] && y == vars->walls->y[0])
    {
        if (recup == vars->collectible->max)
            kill_all(vars);
        else
            return (1);
    }
    while (i < vars->collectible->max)
    {
        if (x == vars->collectible->x[i] && y == vars->collectible->y[i])
        {
            recup++;
            vars->collectible->x[i] = 0;
            vars->collectible->y[i] = 0;
            printf("---COLLECTIBLE RAMASSE = [%d/%d]\n", recup, vars->collectible->max);
            return (0);
        }
        i++;
    }
    i = 1;
    while (i < vars->walls->max)
    {
        if (x == vars->walls->x[i] && y == vars->walls->y[i])
        {
            printf("ITS A WALL PUTAIN");
            return(1);
        }
        i++;
    }
    return (0);
}

void    compteur_de_pas()
{
    static int i = 0;
    printf("%d\n", i);
    i++;
}

int    moove_soldat(int keycode, t_mlx *vars)
{    
    // printf("POSS = %d, %d\n", vars->soldat->x, vars->soldat->y);
    // printf("SOLDAT PATH: %s\n", vars->soldat->relative_path);
    // printf("SOLDAT IMG: [%p]\n", vars->soldat->img);

    if (keycode == 65307 || keycode == 0)
        kill_all(vars);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->soldat->x, vars->soldat->y);
    //mlx_destroy_image(vars->mlx_win,vars->soldat->img);
    if (keycode == RIGHT && !is_obstacle(vars, vars->soldat->x + IMG_BITS, vars->soldat->y))
    {    
        vars->soldat->x += IMG_BITS;
    }    
    if (keycode == LEFT && !is_obstacle(vars, vars->soldat->x - IMG_BITS, vars->soldat->y))
    {
        vars->soldat->x -= IMG_BITS;
    }
    if (keycode == UP && !is_obstacle(vars, vars->soldat->x, vars->soldat->y - IMG_BITS))
    {
        vars->soldat->y -= IMG_BITS;
    }
    if (keycode == DOWN && !is_obstacle(vars, vars->soldat->x, vars->soldat->y + IMG_BITS))
    {
        vars->soldat->y += IMG_BITS;
    }
    printf("pos: %dx, %dy // ", vars->soldat->x, vars->soldat->y);
    printf("ascii: [%d]\n", keycode);
    compteur_de_pas();
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, vars->soldat->x, vars->soldat->y);
    return (0);
}