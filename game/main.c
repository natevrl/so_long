/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/18 22:58:23 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	isnot_ber(char *str)
{
	size_t	begin;

	begin = ft_strlen(str) - 4;
	if (ft_strncmp(str + begin, ".ber", 4) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	if (isnot_ber(av[1]) != 0)
	{
		printf("Error\nInvalid map name\n");
		return (1);
	}
	game_driver(av[1]);
	return (0);
}
