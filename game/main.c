/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/18 14:43:22 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* ERREURS DE MAP :
1 - minimum 1 collecs, 1 player, 1 escape
2 - map entourer uniquement de murs (1)
3 - fichier en .ber obliger
4 - nest pas un dossier .ber
5 - arguments == 2
6 - les lignes font la meme taille
7 - AUTRE que 1, 0, P, E, C
*/

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
		return (0);
	}
	if (isnot_ber(av[1]) != 0)
	{
		printf("Error\nInvalid map name\n");
		return (0);
	}
	game_driver(av[1]);
	return (0);
}
