/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:43 by v3r               #+#    #+#             */
/*   Updated: 2022/01/12 21:53:38 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
# include <string.h>
# include <errno.h>
#include <mlx.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"


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

typedef struct s_mlx
{
    void	*mlx;
	void	*mlx_win;
	t_img	*maps;
	t_img	*soldat;
} t_mlx;



int	closett(int keycode, t_mlx *vars);

void	my_mlx_pixel_put(img_data *data, int x, int y, int color);
int	key_hook(int keycode, t_mlx *vars);
void    carre(img_data img);
void    triangle_rectangle(img_data img);
void    triangle_isocele(img_data img);


#endif