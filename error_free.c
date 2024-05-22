/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:31:59 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 18:35:43 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	short	x;

	x = 0;
	while (map[x]) // free_map przyjmuje **map, czyli wskaznik do tablicy wskaznikow; wystarczy wiec ze zwolnie pamiec dla kazdego wskaznika z tablicy, na ktora kieruje wskaznik
	{
		free(map[x])
		x++;
	}
	free(map);
}

void	error(char **map, char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg); // wypisuje wiadomosc, ktora zawarlem w wywolaniu funkcji w innych plikach
	if (map && map[0])
		free_map(map); // zwalniam pamiec dla mapy jesli mapa jest zaalokowana
	exit(1); // wartosc inna niz 0 w nawiasie wskazuje na zakonczenie z bledem; gdyby bylo 0 to znaczy ze program zakonczyl dzialanie bez bledow
}