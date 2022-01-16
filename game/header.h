/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:43 by v3r               #+#    #+#             */
/*   Updated: 2022/01/16 23:53:13 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"


# define IMG_BITS 32
// code ascii des touches WASD
# define UP 122
# define DOWN 115
# define LEFT 113
# define RIGHT 100

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				img_data;

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int 	x;
	int		y;
	int		starting_position;
} t_img;

typedef struct s_tuple
{
	int *x;
	int *y;
	int max;
	int	nb_looted;
}	t_tuple;


typedef struct s_mlx
{
	int		win_height;
	int		win_width;
	int		is_player;
	int		is_escape;
    void	*mlx;
	void	*mlx_win;
	t_img	*maps;
	t_img	*player;
	t_tuple	*walls;
	t_tuple	*collectible;
	//t_coord	*escape;
} t_mlx;




t_mlx   *init_all(char *path);
void    init_map(t_mlx *vars, char *str);
void    map_size(t_mlx *vars, char *str);
void    init_tuples_walls(t_mlx *vars);
void    init_tuples_collecibles(t_mlx *vars);

void    put_wall(t_mlx *vars, int x, int y);
void    put_ground(t_mlx *vars, int x, int y);
void    put_collectible(t_mlx *vars, int x, int y);
void    put_escape(t_mlx *vars, int x, int y);
void    put_player(t_mlx *vars, int x, int y);

void    number_of(t_mlx *vars, char *str);
void    kill_all(t_mlx *vars);
void    compteur_de_pas();
int is_wall(t_mlx *vars, int x, int y);
void is_collectible(t_mlx *vars, int x, int y);
int is_escape(t_mlx *vars, int x, int y);
int ucango(t_mlx *vars, int x, int y);
int    moove_player(int keycode, t_mlx *vars);

#endif