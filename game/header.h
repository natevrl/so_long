/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:43 by v3r               #+#    #+#             */
/*   Updated: 2022/01/14 22:14:52 by v3r              ###   ########.fr       */
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
    void	*mlx;
	void	*mlx_win;
	t_img	*maps;
	t_img	*player;
	t_tuple	*walls;
	t_tuple	*collectible;
	//t_coord	*escape;
} t_mlx;



int    moove_player(int keycode, t_mlx *vars);
void    init_map(t_mlx *vars, char *str);
int   kill_hook(int keycode, t_mlx *vars);

void	my_mlx_pixel_put(img_data *data, int x, int y, int color);
int	key_hook(int keycode, t_mlx *vars);
void    carre(img_data img);
void    triangle_rectangle(img_data img);
void    triangle_isocele(img_data img);
void	number_of(t_mlx *vars, char *str);





#endif