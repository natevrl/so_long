/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 16:18:25 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int    moove_player(int keycode, t_mlx *vars)
{    
    if (keycode == 65307)
        mlx_loop_end(vars->mlx);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->player->x, vars->player->y);
    if ((keycode == RIGHT || keycode == RIGHTA) && ucango(vars, vars->player->x + IMG_BITS, vars->player->y))
        vars->player->x += IMG_BITS;   
    if ((keycode == LEFT || keycode == LEFTA) && ucango(vars, vars->player->x - IMG_BITS, vars->player->y))
        vars->player->x -= IMG_BITS;
    if ((keycode == UP || keycode == UPA) && ucango(vars, vars->player->x, vars->player->y - IMG_BITS))
        vars->player->y -= IMG_BITS;
    if ((keycode == DOWN || keycode == DOWNA) && ucango(vars, vars->player->x, vars->player->y + IMG_BITS))
        vars->player->y += IMG_BITS;
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, vars->player->x, vars->player->y);
    return (0);
}