/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:43:31 by v3r               #+#    #+#             */
/*   Updated: 2022/01/04 01:21:34 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void    triangle_rectangle(img_data img)
{
    int x = 0;
    int y = 0;

    while (y < 60)
    {
        x = 0;
        while (x != y)
        {
	        my_mlx_pixel_put(&img, 960 + x, 840 + y, 0x000000FF);
            x++;
        }
        y++;
    }
}

void    triangle_isocele(img_data img)
{

    int y;
    int x;

    y = 0;
    while (y < 60)
    {
	    my_mlx_pixel_put(&img, 960 + y, 240 + y, 0x00FF0000);
	    my_mlx_pixel_put(&img, 960 - y, 240 + y, 0x0000FF00);
        if (y == 59)
        {
            x = y;
            while (x-- != 0)
        	    my_mlx_pixel_put(&img, 960 + x, 240 + y, 0x0000FF00);
            while (x++ != y)
        	    my_mlx_pixel_put(&img, 960 - x, 240 + y, 0x000000FF);
        }
        y++;
    }
}