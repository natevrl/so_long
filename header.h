/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:43 by v3r               #+#    #+#             */
/*   Updated: 2022/01/04 01:26:49 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <mlx.h>



typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				img_data;

typedef struct main_vars
{
    void	*mlx;
	void	*mlx_win;
} m_vars;

int	closett(int keycode, m_vars *vars);

void	my_mlx_pixel_put(img_data *data, int x, int y, int color);
int	key_hook(int keycode, m_vars *vars);
void    carre(img_data img);
void    triangle_rectangle(img_data img);
void    triangle_isocele(img_data img);


#endif