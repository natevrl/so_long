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


int	exit_hook(int keycode, m_vars *vars)
{
    if (keycode == 65307 || keycode == 0)
        exit(1);
   printf("%d, ascii =  %c\n", keycode, keycode);
    
}

// Sutilise avec NotionNotify (track la souris en x, y)

int	mouse_move(int x, int y, m_vars *vars)
{
   printf("%d, %d\n", x, y);

}

// S'utilise avec ButtonPress ou ButtonRelease (affiche la position x y lors du click)
int	mouse_position(int keycode, int x, int y, m_vars *vars)
{
        if (keycode == 1 && x == 1904 && y == 10)
            printf("%d, %d\n", x, y);
        else
            printf("%d\n", keycode);
}


// int	closett(int keycode, m_vars *vars)
// {
// 	if (keycode == 65307)
//         mlx_destroy_window(vars->mlx, vars->mlx_win);
// 	return (0);
// }

int loophook(int hook)
{
    static int i = 0;
    if(hook = 97)
        i++;
    return(i);
}

//!!!!!!!NE PAS OUBLIER DE FREE vars->mlx A LA FIN!!!!!!!
int	main(void)
{
    img_data	img;
    m_vars      vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    carre(img);
    // triangle_rectangle(img);
    // triangle_isocele(img);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 200);
    
    mlx_hook(vars.mlx_win, 17, 1L<<17, exit_hook, (void *)0);
    mlx_key_hook(vars.mlx_win, exit_hook, &vars);
    //mlx_mouse_hook(vars.mlx_win, key_hook, &vars);
	//mlx_hook(vars.mlx_win, 8, 1L<<5, mouse_position, &vars);
    //triangle_isocele(img);
    mlx_loop_hook(vars.mlx, ft_ps_random, &vars);
    mlx_hook(vars.mlx_win, 3, 1L<<1, exit_hook, &vars);
   // mlx_key_hook(vars.mlx_win, key_hook, &vars);
    mlx_loop(vars.mlx); 
    return (0);
}
