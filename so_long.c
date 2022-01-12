/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/12 22:39:07 by v3r              ###   ########.fr       */
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
int	event_hook(int keycode)
{
    if (keycode == 65307 || keycode == 0)
        exit(1);
}

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

void    mapping(t_mlx *vars)
{
    int i;
    int j = 0;
    int y;
    int x = 0;
   
    while (j < 10)
    {
        i = 0;
        y = 0;
        while (i < 34)
        {
            mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, y, x);
            y += 32;
            i++;
        }
        x += 32;
        j++;
    }
}

void    init_soldat(int keycode, t_mlx *vars)
{    
    if (keycode == 65307 || keycode == 0)
        exit(1);
    if (keycode == 100)
    {
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->soldat->x, vars->soldat->y);
        vars->soldat->x += 32;
    }
        if (keycode == 113)
    {
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->soldat->x, vars->soldat->y);
        vars->soldat->x -= 32;
    }
        if (keycode == 122)
    {
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->soldat->x, vars->soldat->y);
        vars->soldat->y -= 32;
    }
        if (keycode == 115)
    {
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->soldat->x, vars->soldat->y);
        vars->soldat->y += 32;
    }
    printf("ascii: [%d]\n", keycode);
    printf("%p, %p\n", vars->soldat->img, vars->mlx);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, vars->soldat->x, vars->soldat->y);

}

void    eject_soldat(int keycode, t_mlx *vars)
{    
    if (keycode == 100)
        mlx_destroy_image(vars->mlx, vars->soldat->img);
        
    
}

// int avancer(int keycode, t_mlx vars)
// {
//     if (keycode == 100)event_hook
//     {
//         soldat(32, 32, vars);
//     }
// }
void    init_map(t_mlx *vars)
{
   	int fd;
    char *gnl;
    int j;
    int i;
    int y;
    int x = 0;;

	fd = open("maps.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() error", 1);
		return ;
	}
    i = -1;
    while (++i < 10)
    {
        gnl = get_next_line(fd);
        printf("%s", gnl);
        j = -1;
        y = 0;
        while (gnl[++j])
        {
            if(gnl[j] == '1')
            {
                vars->maps->relative_path = "./rock.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height); 
            }
            else if(gnl[j] == 'C')
            {
                vars->maps->relative_path = "./collectible.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height); 
            }
            else if(gnl[j] == 'E')
            {
                vars->maps->relative_path = "./escape.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height); 
            }
            else if(gnl[j] == 'P')
            {
                vars->maps->relative_path = "./rock.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->soldat->relative_path, &vars->soldat->img_width, &vars->soldat->img_height); 
            }
            else
            {
                vars->maps->relative_path = "./center.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);    
            }
            mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, y, x);
            y += 32;
        }
        x += 32;
        free(gnl);
    }
}
//!!!!!!!NE PAS OUBLIER DE FREE vars->mlx A LA FIN!!!!!!!
int	main(void)
{
 //   img_data	img_s;
    t_mlx      vars;
    t_img character;
    t_img map;

    
    //init windows
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1088, 320, "NbenhaGame");

    // init map
    // map.relative_path = 0;
	// map.img = mlx_xpm_file_to_image(vars.mlx, map.relative_path, &map.img_width, &map.img_height); 
    //init character
    character.relative_path = "./character.xpm";
	character.img = mlx_xpm_file_to_image(vars.mlx, character.relative_path, &character.img_width, &character.img_height);
    character.x = 32;
    character.y = 32;
    //init liste chainee
    vars.maps = &map;
    vars.soldat = &character;
    
    // printf("%d[%p] // %d[%p]\n", character.img, character.img, vars.soldat->img, vars.soldat->img);
    // printf("%d[%p] // %d[%p]\n", character.x, character.x, vars.soldat->x, vars.soldat->x);

    init_map(&vars);
    //mapping(&vars);
    mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.soldat->img, vars.soldat->x, vars.soldat->y);
    
    //img_s.img = mlx_new_image(vars.mlx, 320, 720);
	//img_s.addr = mlx_get_data_addr(img_s.img, &img_s.bits_per_pixel, &img_s.line_length, &img_s.endian);
    //carre(img_s);
    mlx_hook(vars.mlx_win, 17, 1L<<17, event_hook, (void *)0);
  	mlx_hook(vars.mlx_win, 2, 1L << 0, init_soldat, &vars);
	//mlx_hook(vars.mlx_win, 3, 1L << 1, eject_soldat, &vars);
  //  mlx_loop_hook(vars.mlx, avancer, &vars);
	//mlx_hook(vars.mlx_win, 6, 1L<<6, mouse_move, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
