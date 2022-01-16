/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/16 21:31:00 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int    moove_player(int keycode, t_mlx *vars)
{    
    if (keycode == 65307)
        mlx_loop_end(vars->mlx);
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