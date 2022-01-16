/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:41:09 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 00:30:41 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int intstrlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    check_walls(t_mlx *vars, int i, int last_nl, char *buffer)
{
    int i;

    i = -1;
    if (line == 0 || line == vars->win_height)
    {
        while (gnl[++i] != '\n' && gnl[i])
        {
            if (gnl[i] != '1')
            {
                perror("Invalid map\n");
                kill_all(vars);
            }
        }
    }
}

// calcule la resolution de la map et le nombre de walls & collectibles
// check si la map est bien valide
void    map_size(t_mlx *vars, char *str)
{
    char buffer[32400];
    int ret;
    int i;
    int fd;
    int last_nl;
    
	fd = open(str, O_RDONLY);
    if (fd == -1)
    {
        perror("open() error\n");
        kill_all(vars);
    }
    ret = read(fd, buffer, 32400);
    buffer[ret] = '\0';
    i = 0;
    last_nl = 0;
    while (buffer[i])
    {
        if (buffer[i] == 'C')   
            vars->collectible->max++;
        else if (buffer[i] == '1')
            vars->walls->max++;
        else if (buffer[i] == 'P')
            vars->is_player++;
        else if (buffer[i] == 'E')
            vars->is_escape++;
        if (buffer[i] == '\n' || buffer[i + 1] == '\0')
        {
            if (vars->win_height == 0 || buffer[i + 1] == '\0')
            {
                check_walls(vars, i, last_nl, buffer)
            }
            vars->win_height++;
            last_nl = i;
        }
        i++;
    }
    init_tuples_walls(vars);
    init_tuples_collecibles(vars);
    //printf("COLLEC===%d\n",vars->collectible->max );

    if (vars->collectible->max == 0 || vars->is_escape != 1 || vars->is_player != 1)
    {
        printf("%d\n",vars->collectible->max );
        printf("%d\n",vars->walls->max );
        printf("%d\n", vars->is_player);
        printf("%d\n", vars->is_escape);
        perror("Invalid map\n");
        kill_all(vars);
    }
    vars->win_width = ((i + 1 ) - vars->win_height) / vars->win_height;
    close(fd);        
}

void    check_maps_error(t_mlx *vars, char *gnl)
{
    int len;
    static int i = 1;

    len = intstrlen(gnl);
    if (gnl[len - 1] == '\n')
        len--;
    if (len != vars->win_width && i == 1)
    {
        perror("Invalid map\n");
        kill_all(vars);
        i = 0;
    }
}


void    draw_line(t_mlx *vars, char *gnl)
{
    int i;
    int x;
    static int y = 0;

    
    check_maps_error(vars, gnl);
    i = -1;
    x = 0;
    while (gnl[++i])
    {
        if(gnl[i] == '1')
            put_wall(vars, x, y);
        else if(gnl[i] == 'C')
            put_collectible(vars, x, y);
        else if(gnl[i] == 'E')
            put_escape(vars, x, y);
        else if(gnl[i] == 'P')
            put_player(vars, x, y);
        else if (gnl[i] == '0')
            put_ground(vars, x, y);
        x += IMG_BITS;
    }
    y += IMG_BITS;
    free(gnl);
}



void    init_map(t_mlx *vars, char *str)
{
   	int fd;
    char *gnl;
    int line;

	fd = open(str, O_RDONLY);
    line = 0;
    while ((gnl = get_next_line(fd)))
    {
        printf("%d, %d", line, vars->win_height);
        if (line == 0 || line == vars->win_height) 
            check_walls(vars, line, gnl);
        draw_line(vars, gnl);
        line++;
    }
    vars->maps->relative_path = "./images/center.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);
    close(fd);  
}