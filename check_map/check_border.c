/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:40:56 by mrechuli          #+#    #+#             */
/*   Updated: 2024/05/20 19:32:26 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// map jest tablica wskaznikow, gdzie kazdy wskaznik zawiera jeden wiersz mapy
// check_border sprawdza czy na krawedziach jest 1, jesli nie to wyrzuca blad

void	check_border(char **map)
{
	size_t	width;
	size_t	height;
	short	x; // short przechowuje liczby calkowite jak int, ale jego zakres jest mniejszy, co za tym idzie zajmuje mniej miejsca
	short	y;

	width = map_width(map[0]) - 1; // map to wskaznik do tablicy wskaznikow. map[0] wskazuje wiec na pierwszy wiersz. Dlugosc tego wiersza to jest szerokosc mapy. map_width sprawdza dlugosc pierwszego wiersza (map[0]). Na koncu odejmuje -1, aby miec indeks ostatniej kolumny
	height = map_height(map) - 1; // map to wskaznik do tablicy wskaznikow. map_height policzy ilosc elementow w map, czyli ilosc wierszy. To nam da wysokosc mapy. Na koncu odejmuje -1, aby miec indeks ostatniego wiersza
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (x == 0 || x == height || y == 0 || y == width)
			{
				if (map[x][y] != '1')
					error(map, "The map must be surrounded by walls");
			}
			y++;
		}
		x++;
	}
}
