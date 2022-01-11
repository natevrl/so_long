/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/10 22:39:11 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	my_mlx_pixel_put(img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    carre(img_data img)
{
    int x;
    int y;

    x = -1;
    while (++x != 60)
    {
        y = -1;
        while (++y != 60)
	        my_mlx_pixel_put(&img, 960 + x, 540 + y, 0x0000FF00);
    }
}

// 65307 sur linux = ESC // 53 sur MAC
// int	exit_hook(int keycode)
// {
//     if (keycode == 53)
//         exit(1);
//    printf("%d, ascii =  %c\n", keycode, keycode);
// }

// Sutilise avec NotionNotify (track la souris en x, y)
// int	mouse_move(int x, int y, m_vars *vars)
// {
//    printf("%d, %d\n", x, y);
// }

// S'utilise avec ButtonPress ou ButtonRelease (affiche la position x y lors du click)
int	mouse_position(int keycode, int x, int y)
{
        if (keycode == 1 && x == 1904 && y == 10)
            printf("%d, %d\n", x, y);
        else
            printf("%d\n", keycode);
        return (0);
}


// int	closett(int keycode, m_vars *vars)
// {
// 	if (keycode == 65307)
//         mlx_destroy_window(vars->mlx, vars->mlx_win);
// 	return (0);
// }

void    mapping(m_vars vars)
{
    int i;
    int j = 0;
    int y;
    int x = 0;
    map_s map;
    
    map.relative_path = "./ground5.xpm";
	map.img = mlx_xpm_file_to_image(vars.mlx, map.relative_path, &map.img_width, &map.img_height);
    while (j < 7)
    {
        i = 0;
        y = 0;
        while (i < 10)
        {
            mlx_put_image_to_window(vars.mlx, vars.mlx_win, map.img, y, x);
            y += 128;
            i++;
        }
        x += 128;
        j++;
    }
}

void    character(int x, int y)
{
    map_s character;
    m_vars vars;

    character.relative_path = "./stone1.xpm";
	character.img = mlx_xpm_file_to_image(vars.mlx, character.relative_path, &character.img_width, &character.img_height);
    mlx_put_image_to_window(vars.mlx, vars.mlx_win, character.img, x, y);
}

int avancer(int keycode)
{
    if (keycode == 125)
    {
        character(128, 128);
    }
}

//!!!!!!!NE PAS OUBLIER DE FREE vars->mlx A LA FIN!!!!!!!
int	main(void)
{
 //   img_data	img_s;
    m_vars      vars;
    //map_s       maps;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1280, 720, "NbenhaGame");


    mapping(vars);
    //character(128, 128);
    
    //img_s.img = mlx_new_image(vars.mlx, 1280, 720);
	//img_s.addr = mlx_get_data_addr(img_s.img, &img_s.bits_per_pixel, &img_s.line_length, &img_s.endian);
    //carre(img_s);
    // mlx_hook(vars.mlx_win, 17, 1L<<17, exit_hook, (void *)0);
    // mlx_key_hook(vars.mlx_win, exit_hook, &vars);
    mlx_key_hook(vars.mlx_win, avancer, &vars);
    //mlx_mouse_hook(vars.mlx_win, key_hook, &vars);
	//mlx_hook(vars.mlx_win, 8, 1L<<5, mouse_position, &vars);
    // mlx_hook(vars.mlx_win, 3, 1L<<1, exit_hook, &vars);
    mlx_loop(vars.mlx); 
    return (0);
}
