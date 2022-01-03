/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/03 20:30:53 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	my_mlx_pixel_put(img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	key_hook(int keycode, m_vars *vars)
{
        printf("Keycode = %d // ascii = %c\n", keycode, keycode);
}

// Sutilise avec NotionNotify (track la souris en x, y)

int	mouse_move(int x, int y, m_vars *vars)
{
   printf("%d, %d\n", x, y);

}

// S'utilise avec ButtonPress ou ButtonRelease (affiche la position x y lors du click)
int	mouse_position(int keycode, int x, int y, m_vars *vars)
{
        if (keycode == 1)
            printf("%d, %d\n", x, y);
        else
            printf("%d\n", keycode);
}


int	closett(int keycode, m_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	return (0);
}

int	main(void)
{
    img_data	img;
    m_vars      vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    carre(img);
    triangle_rectangle(img);
    triangle_isocele(img);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
    
    // mlx_key_hook(vars.mlx_win, key_hook, &vars);
    //  mlx_mouse_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 6, 1L<<6, mouse_move, &vars);
    mlx_loop(vars.mlx); 
    return (0);
}