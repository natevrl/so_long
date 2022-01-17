/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:00:31 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 19:01:59 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    malloc_error(t_mlx *vars)
{
    perror("malloc() error");
    kill_all(vars);
}

void    invalid_map_error(t_mlx *vars)
{
    printf("Invalid map\n");
    kill_all(vars);
}

void    check_open_error(t_mlx *vars, int fd)
{
    if (fd == -1)
    {
        perror("open() error");
        kill_all(vars);
    }
}

void    check_read_error(t_mlx *vars, int ret)
{
    if (ret == -1)
    {
        perror("read() error");
        kill_all(vars);
    }
}

int    walls_error(t_mlx *vars, int line, char *gnl)
{
    int i;

    i = -1;
    if (line == 1 || line == vars->win_height)
    {
        while (gnl[++i] != '\n' && gnl[i])
            if (gnl[i] != '1')
                return (1);
    }
    else
    {
        if (gnl[0] != '1' || gnl[ft_strlen(gnl) - 2] != '1')
            return (1);
    }
    return (0);
}

int    line_bad_len(t_mlx *vars, char *gnl)
{
    int len;
    static int interupt = 1;

    len = intstrlen(gnl);
    if (gnl[len - 1] == '\n')
        len--;
    if (len != vars->win_width && interupt == 1)
        return (1);
    return (0);
}
