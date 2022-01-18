/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by v3r               #+#    #+#             */
/*   Updated: 2022/01/18 20:37:00 by nbenhado         ###   ########.fr       */
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
8 - PROTEGER toutes les fonctions systemes (que je nai pas coder moi meme), retourner si echec (3e correction so_long) pour eviter les segfault
9 - return et exit = return (1) si erreur, return(0) et exit(0) si le programme se termine normalement
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
