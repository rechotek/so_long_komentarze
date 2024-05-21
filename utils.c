/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:15:11 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 19:15:11 by marvin           ###   ########.fr       */
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