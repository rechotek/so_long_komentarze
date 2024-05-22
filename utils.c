/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:15:11 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 17:00:35 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Liczymy tu szerokosc mapy. *map wskazuje na ciag znakow. Jesli policzymy
// jego dlugosc to otrzymamy szerokosc mapy

size_t	map_width(char *map) // *map jest wskaznikiem na ciag znakow (czyli jednego wiersza mapy)
{
	size_t	x;

	x = 0;
	while (map[x] != '\n' && map[x] != '\0')
		x++;
	return (x);
}

// Liczymy tu wysokosc mapy. **map wskazuje na tablice z ciagami znakow. Jesli
// policzymy wszystkie ciagi znakow, czyli przejdziemy przez wszystkie
// elementy tablicy to otrzymamy wysokosc mapy.

size_t	map_height(char **map) // **map jest wskaznikiem do tablicy wskaznikow do ciagow znaku
{
	size_t	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

// sprawdza czy zostaly zebrane wszystkie collectibles (C) oraz exit (E)

bool	is_all_collected(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}

// szukam tutaj wspolrzednych (stad GPS), na ktorych jest postac (P) oraz wyjscie (E)
// gdy napotkam na danym miejscu w tabeli P lub E to przypisuje do p_pos lub e_pos (one sa zapisane w strukturze)
// obecna wartosc x oraz y

void	find_gps(char **map, short *p_pos, short *e_pos)
{
	short	x;
	short	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P' && p_pos)
			{
				p_pos[0] = x;
				p_pos[1] = y;
			}
			if (map[x][y] == 'E' && e_pos)
			{
				e_pos[0] = x;
				e_pos[1] = y;
			}
			y++;
		}
		x++;
	}
}