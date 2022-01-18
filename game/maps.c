/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:41:09 by v3r               #+#    #+#             */
/*   Updated: 2022/01/18 22:49:26 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// calcule la resolution de la map et le nombre de walls & collectibles
// check si la map contient le bon nombre d'elements
static void	count_elements(t_mlx *vars, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'C')
			vars->collectible->max++;
		else if (buffer[i] == '1')
			vars->walls->max++;
		else if (buffer[i] == 'N')
			vars->enemies->max++;
		else if (buffer[i] == 'P')
			vars->is_player++;
		else if (buffer[i] == 'E')
			vars->is_escape++;
		else if (buffer[i] != '\n' && buffer[i] != '0')
			invalid_map_error(vars, buffer);
		if (buffer[i] == '\n' || buffer[i + 1] == '\0')
			vars->win_height++;
		i++;
	}
	if (vars->collectible->max == 0 || vars->is_escape != 1
		|| vars->is_player != 1)
		invalid_map_error(vars, buffer);
	vars->win_width = ((i + 1) - vars->win_height) / vars->win_height;
}

void	map_parsing(t_mlx *vars, char *str)
{
	char	buffer[BUFF_SIZE];
	char	*all_maps;
	int		ret;
	int		fd;

	fd = open(str, O_RDONLY);
	check_open_error(vars, fd);
	ret = 1;
	all_maps = 0;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		check_read_error(vars, ret, all_maps);
		buffer[ret] = '\0';
		all_maps = ftstrjoin(all_maps, buffer);
	}
	count_elements(vars, all_maps);
	free(all_maps);
	close(fd);
}

int free_return(char *str)
{
	free(str);
	return (0);
}

static int	draw_line(t_mlx *vars, char *gnl)
{
	int			i;
	int			x;
	static int	y = 0;

	i = -1;
	x = 0;
	while (gnl[++i])
	{
		if (gnl[i] == '1')
		{
			if (!(put_wall(vars, x, y)))
				return(free_return(gnl));
		}
		else if (gnl[i] == 'C')
		{
			if (!(put_collectible(vars, x, y)))
				return(free_return(gnl));
		}
		else if (gnl[i] == '0')
		{
			if (!(put_ground(vars, x, y)))
				return(free_return(gnl));
		}

		x += IMG_BITS;
	}
	y += IMG_BITS;
	return (1);
}

static int	draw_line_bis(t_mlx *vars, char *gnl)
{
	int			i;
	int			x;
	static int	y = 0;

	i = -1;
	x = 0;
	while (gnl[++i])
	{
		if (gnl[i] == 'N')
		{
			if (!(put_enemies(vars, x, y)))
				return(free_return(gnl));
		}
		else if (gnl[i] == 'E')
		{
			if (!(put_escape(vars, x, y)))
				return(free_return(gnl));
		}
		else if (gnl[i] == 'P')
		{
			if (!(put_player(vars, x, y)))
				return(free_return(gnl));
		}
		x += IMG_BITS;
	}
	y += IMG_BITS;
	return (1);
}

void	map_drawer(t_mlx *vars, char *str)
{
	int		fd;
	char	*gnl;
	int		line;
	int		error;

	fd = open(str, O_RDONLY);
	check_open_error(vars, fd);
	line = 1;
	error = 0;
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		if (line_bad_len(vars, gnl) || walls_error(vars, line, gnl))
			error++;
		if (!(draw_line(vars, gnl)) || !(draw_line_bis(vars, gnl)))
			error++;
		else
			free(gnl);
		line++;
	}
	vars->maps->r_path = "./images/center.xpm";
	if (!(vars->maps->img = mlx_xpm_file_to_image(vars->mlx, vars->maps->r_path,
			&vars->maps->img_width, &vars->maps->img_height)))
			error++;
	if (error > 0)
		invalid_map_error(vars, 0);
	close(fd);
}
