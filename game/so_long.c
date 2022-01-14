/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/14 20:39:55 by v3r              ###   ########.fr       */
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

void    kill_all(t_mlx *vars)
{

    mlx_destroy_image(vars->mlx, vars->player->img);
    mlx_destroy_image(vars->mlx, vars->maps->img);
    mlx_destroy_window(vars->mlx, vars->mlx_win);
    mlx_destroy_display(vars->mlx);
    free(vars->player);
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

void    compteur_de_pas()
{
    static int i = 1;
    printf("%d\n", i);
    i++;
}

int is_wall(t_mlx *vars, int x, int y)
{
    int i;

    i = 0;
    while (++i < vars->walls->max)
        if (x == vars->walls->x[i] && y == vars->walls->y[i])
            return(1);
    return (0);   
}

int is_escape(t_mlx *vars, int x, int y)
{
    if (x == vars->walls->x[0] && y == vars->walls->y[0])
    {
        if (vars->collectible->nb_looted == vars->collectible->max)
        {
            compteur_de_pas();            
            kill_all(vars);
        }
        else
            return (1);
    }
    return (0);
}

void is_collectible(t_mlx *vars, int x, int y)
{
    int i;
    
    i = 0;
    while (i < vars->collectible->max)
    {
        if (x == vars->collectible->x[i] && y == vars->collectible->y[i])
        {
            vars->collectible->nb_looted++;
            vars->collectible->x[i] = 0;
            vars->collectible->y[i] = 0;
            printf("---COLLECTIBLE RAMASSE = [%d/%d]\n", vars->collectible->max, vars->collectible->max);
        }
        i++;
    }
}

int ucango(t_mlx *vars, int x, int y)
{
    if (is_wall(vars, x, y))
        return (0);
    if (is_escape(vars, x, y))
        return (0);
    is_collectible(vars, x, y);
    compteur_de_pas();
    return (1);
}

int    moove_player(int keycode, t_mlx *vars)
{    
    if (keycode == 65307 || keycode == 0)
        kill_all(vars);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->player->x, vars->player->y);
    if (keycode == RIGHT && ucango(vars, vars->player->x + IMG_BITS, vars->player->y))
        vars->player->x += IMG_BITS;   
    if (keycode == LEFT && ucango(vars, vars->player->x - IMG_BITS, vars->player->y))
        vars->player->x -= IMG_BITS;
    if (keycode == UP && ucango(vars, vars->player->x, vars->player->y - IMG_BITS))
        vars->player->y -= IMG_BITS;
    if (keycode == DOWN && ucango(vars, vars->player->x, vars->player->y + IMG_BITS))
        vars->player->y += IMG_BITS;
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, vars->player->x, vars->player->y);
    return (0);
}