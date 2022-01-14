/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/14 20:30:07 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
    vars->walls->x = malloc(sizeof(int) * vars->walls->max);
    if (vars->walls->x == 0)
        return ;
    vars->walls->y = malloc(sizeof(int) * vars->walls->max);
    if (vars->walls->y == 0)
        return ;
}

void    init_tuples_collecibles(t_mlx *vars)
{
    vars->collectible->x = malloc(sizeof(int) * vars->collectible->max);
    if (vars->collectible->x == 0)
        return ;
    vars->collectible->y = malloc(sizeof(int) * vars->collectible->max);
    if (vars->collectible->y == 0)
        return ;
}
void    put_wall(t_mlx *vars, int x, int y)
{
    static int f = -1;
    
    vars->walls->x[++f] = x;
    vars->walls->y[f] = y;
    vars->maps->relative_path = "./rock.xpm";
    vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
    mlx_destroy_image(vars->mlx, vars->maps->img);
}
void    put_escape(t_mlx *vars, int x, int y)
{
    vars->walls->x[0] = x;
    vars->walls->y[0] = y;
    vars->maps->relative_path = "./escape.xpm";
    vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height); 
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
    mlx_destroy_image(vars->mlx, vars->maps->img);
}
void    put_ground(t_mlx *vars, int x, int y)
{
    vars->maps->relative_path = "./center.xpm";
    vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);    
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
    mlx_destroy_image(vars->mlx, vars->maps->img);
}
void    put_player(t_mlx *vars, int x, int y)
{
    vars->player->x = x;
    vars->player->y = y;
    vars->player->relative_path = "./character.xpm";
    vars->player->img = mlx_xpm_file_to_image(vars->mlx, vars->player->relative_path, &vars->player->img_width, &vars->player->img_height); 
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player->img, x, y);
}

void    put_collectible(t_mlx *vars, int x, int y)
{
    static int  k = -1;

    vars->collectible->x[++k] = x;
    vars->collectible->y[k] = y;
    vars->maps->relative_path = "./collectible.xpm";
    vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height); 
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->maps->img, x, y);
    mlx_destroy_image(vars->mlx, vars->maps->img);
}

void    init_map(t_mlx *vars, char *str)
{
   	int fd;
    char *gnl;
    int j;
    int i;
    int x;
    int y = 0;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() error", 1);
		return ;
	}
    i = -1;
    while (++i < vars->win_height)
    {
        gnl = get_next_line(fd);
        j = -1;
        x = 0;
        while (gnl[++j])
        {
            if(gnl[j] == '1')
                put_wall(vars, x, y);
            else if(gnl[j] == 'C')
                put_collectible(vars, x, y);
            else if(gnl[j] == 'E')
                put_escape(vars, x, y);
            else if(gnl[j] == 'P')
                put_player(vars, x, y);
            else if (gnl[j] == '0')
                put_ground(vars, x, y);
            x += IMG_BITS;
        }
        y += IMG_BITS;
        free(gnl);
    }
    vars->maps->relative_path = "center.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);
    close(fd);  
}

t_mlx   *init_all(char *path)
{
    t_mlx *vars;
    
    vars = malloc(sizeof(t_mlx));
    if (vars == 0)
        return (NULL);
    vars->player = malloc(sizeof(t_img));
    vars->maps = malloc(sizeof(t_img));
    vars->walls = malloc(sizeof(t_tuple));
    vars->collectible = malloc(sizeof(t_tuple));
    if (!vars->walls || !vars->player || !vars->maps || !vars->collectible)
        return (NULL);
    vars->collectible->max = 0;
    vars->collectible->nb_looted = 0;
    vars->walls->max = 0;
    vars->win_width = 0;
    vars->win_height = 0;
    number_of(vars, path);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, IMG_BITS * vars->win_width, IMG_BITS * vars->win_height, "NbenhaGame");
    init_tuples_walls(vars);
    init_tuples_collecibles(vars);
    init_map(vars, path);
    return (vars);
}

int	main(int ac, char **av)
{
    t_mlx      *vars;

    if (ac != 2)
    {
        printf("Invalid number of arguments");
        return (0);
    }
    vars = init_all(av[1]);

    mlx_hook(vars->mlx_win, 17, 1L<<17, moove_player, vars);
  	mlx_hook(vars->mlx_win, 2, 1L << 0, moove_player, vars);
    mlx_loop(vars->mlx);
    return (0);
}
