/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/17 19:39:14 by v3r              ###   ########.fr       */
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
*/

// RESTE A FAIRE :

// ---- 10: gerer le kill_all a la perfection
// ---- 11: gerer les static function et header a la perfection
// ---- 12: gerer le close(fd)
// ---- 13: se decider pour la taille du buffer
// ---- 9 : Norminer

int	isnot_ber(char *str)
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
		printf("Invalid number of arguments");
		return (0);
	}
	if (isnot_ber(av[1]) != 0)
	{
		printf("Invalid map name\n");
		return (0);
	}
	game_driver(av[1]);
	return (0);
}
