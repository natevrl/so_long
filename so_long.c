/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/13 19:53:50 by v3r              ###   ########.fr       */
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

void    init_vars(t_mlx *vars)
{
    
    vars = malloc(sizeof(t_mlx));
}

//penser a proteger tout les mallocs
void    init_tuple(t_mlx *vars, int len)
{

    vars->walls->x = malloc(sizeof(int) * len);
    if (vars->walls->x == 0)
        return ;
    vars->walls->y = malloc(sizeof(int) * len);
    if (vars->walls->y == 0)
        return ;
}

void    init_map(t_mlx *vars)
{
   	int fd;
    char *gnl;
    int j;
    int i;
    int x;
    int y = 0;
    int f = -1;

	fd = open("maps.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() error", 1);
		return ;
	}
    init_tuple(vars, 90);
    i = -1;
    while (++i < 10)
    {
        gnl = get_next_line(fd);
        printf("%s", gnl);
        j = -1;
        x = 0;
        while (gnl[++j])
        {
            if(gnl[j] == '1')
            {
                vars->maps->relative_path = "./rock.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);
                vars->walls->x[++f] = x;
                vars->walls->y[f] = y;
                printf("wall[%d] pos: %dx, %dy\n", f, vars->walls->x[f], vars->walls->y[f]);
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
                vars->walls->x[0] = x;
                vars->walls->y[0] = y;
                printf("ESSSAAPPPPE: %d, %d\n", vars->walls->x, vars->walls->y);
            }
            else if(gnl[j] == 'P')
            {
                vars->soldat->relative_path = "./character.xpm";
                vars->soldat->x = x;
                vars->soldat->y = y;
                printf("POS inside init_map = %d, %d", vars->soldat->x, vars->soldat->y);
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->soldat->relative_path, &vars->soldat->img_width, &vars->soldat->img_height); 
            }
            else if (gnl[j] == '0')
            {
                vars->maps->relative_path = "./center.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);    
            }
            mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
            x += IMG_BITS;
        }
        y += IMG_BITS;
        free(gnl);
    }
    vars->maps->relative_path = "center.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);
}

int is_obstacle(t_mlx *vars, int x, int y)
{
    int i = 1;

    if (x == vars->walls->x[0] && y == vars->walls->y[0])
    {
        printf("ITS THE ESCAPE");
        mlx_destroy_image(vars->mlx, vars->soldat->img);
        return (1);
    }
    while (i < 90)
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

void    moove_soldat(int keycode, t_mlx *vars)
{    
    printf("POSS = %d, %d\n", vars->soldat->x, vars->soldat->y);
    if (keycode == 65307 || keycode == 0)
        exit(1);
    printf("%s", vars->maps->relative_path);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, vars->soldat->x, vars->soldat->y);
    //mlx_destroy_image(vars->mlx_win,vars->soldat);
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
 
    //printf("%p, %p\n", vars->soldat->img, vars->mlx);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, vars->soldat->x, vars->soldat->y);
}

