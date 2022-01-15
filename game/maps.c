/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:41:09 by v3r               #+#    #+#             */
/*   Updated: 2022/01/15 01:34:32 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"




// calcule la resolution de la map et le nombre de walls & collectibles
// check si la map est bien valide
void    map_parsing(t_mlx *vars, char *str)
{
    char buffer[32400];
    int ret;
    int i;
    int fd;
    
	fd = open(str, O_RDONLY);
    ret = read(fd, buffer, 32400);
    buffer[ret] = '\0';
    i = 0;
    while (buffer[i])
    {
        if (buffer[i] == 'C')   
            vars->collectible->max += 1;
        else if (buffer[i] == '1')
            vars->walls->max += 1;
        if (buffer[i] == '\n' || buffer[i + 1] == '\0')
        {
            vars->win_height++;
        }
        i++;
    }
    vars->win_width = ((i + 1 ) - vars->win_height) / vars->win_height;
    close(fd);        
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
    vars->maps->relative_path = "./images/center.xpm";
	vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->relative_path, &vars->maps->img_width, &vars->maps->img_height);
    close(fd);  
}