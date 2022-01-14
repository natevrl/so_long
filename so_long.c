/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:47 by v3r               #+#    #+#             */
/*   Updated: 2022/01/14 15:28:56 by v3r              ###   ########.fr       */
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

void    init_vars(t_mlx *vars)
{
    
    vars = malloc(sizeof(t_mlx));
}



void    number_of(t_mlx *vars, char *str)
{
    char buffer[1000];
    int ret;
    int i;
    int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() error", 1);
		return ;
	}
    vars->collectible->max = 0;
    vars->walls->max = 0;
    vars->win_width = 0;
    vars->win_height = 0;
    ret = 1;
    ret = read(fd, buffer, 999);
    buffer[ret] = '\0';
    
    i = -1;
    while (buffer[++i])
    {
        if (buffer[i] == 'C')   
            vars->collectible->max += 1;
        else if (buffer[i] == '1')
            vars->walls->max += 1;
        if (buffer[i] == '\n')
            vars->win_height += 1;
    }
    vars->win_width = (i - 1) / vars->win_height;
    close(fd);        
}

//penser a proteger tout les mallocs
void    init_tuples_walls(t_mlx *vars)
{
    //vars->walls->max = 90;
    vars->walls->x = malloc(sizeof(int) * vars->walls->max);
    if (vars->walls->x == 0)
        return ;
    vars->walls->y = malloc(sizeof(int) * vars->walls->max);
    if (vars->walls->y == 0)
        return ;
}

void    init_tuples_collecibles(t_mlx *vars)
{


    // vars->collectible->max = 2;
    vars->collectible->x = malloc(sizeof(int) * vars->collectible->max);
    if (vars->collectible->x == 0)
        return ;
    vars->collectible->y = malloc(sizeof(int) * vars->collectible->max);
    if (vars->collectible->y == 0)
        return ;
}


void    init_map(t_mlx *vars, char *str)
{
   	int fd;
    char *gnl;
    int j;
    int i;
    int x;
    int y = 0;
    int f = -1;
    int k = -1;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() error", 1);
		return ;
	}
    init_tuples_walls(vars);
    init_tuples_collecibles(vars);
    printf("LEN COLLECTIBLE: %d\n", vars->collectible->max);
    printf("LEN walls: %d\n", vars->walls->max);
    printf("LEN HEIGHT WINDOW: %d\n", vars->win_height);
    printf("LEN WIDHT WINDOW: %d\n", vars->win_width);
    i = -1;
    while (++i < vars->win_height)
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
                vars->collectible->x[++k] = x;
                vars->collectible->y[k] = y;
                printf("-------COLLECTIBLE[%d] pos: %dx, %dy\n", f, vars->collectible->x[k], vars->collectible->y[k]);

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
                printf("POS inside init_map = %d, %d\n", vars->soldat->x, vars->soldat->y);
	            vars->soldat->img = mlx_xpm_file_to_image(vars->mlx, vars->soldat->relative_path, &vars->soldat->img_width, &vars->soldat->img_height); 
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, x, y);
                printf("SOLDAT IMG: [%p]\n", vars->soldat->img);

            }
            else if (gnl[j] == '0')
            {
                vars->maps->relative_path = "./center.xpm";
	            vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);    
            }
            // if (gnl[j] != '0')
            if (gnl[j] != '\n' && gnl[j] != 'P')
            {                
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
                mlx_destroy_image(vars->mlx, vars->maps->img);
            }
                //printf("[%p]", vars->maps->img);
            x += IMG_BITS;
        }
        y += IMG_BITS;
        free(gnl);
    }
    vars->maps->relative_path = "center.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);
    close(fd);  
}


void    kill_all(t_mlx *vars)
{
    //free(vars->mlx_win);
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
    exit(1);
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



void    moove_soldat(int keycode, t_mlx *vars)
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
 
    //printf("%p, %p\n", vars->soldat->img, vars->mlx);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->soldat->img, vars->soldat->x, vars->soldat->y);
}

