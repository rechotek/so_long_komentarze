/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:04:32 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 17:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Licze ilosci wystapien znakow C, E oraz P. Jesli pojawi sie znak inny niz te
// ktore chcemy miec w programie to wyrzuca false.

bool    verify_characters(char ch, size_t *c, size_t *e, size_t *p)
{
    if (ch == 'C') // kazde wystapienie znaku powoduje powiekszenie o 1 danego pointera
        (*c)++;
    else if (ch == 'E')
        (*e)++;
    else if (ch == 'P')
        (*p)++;
    else if (ch != '0' && ch != '1' && ch != 'T')
        return (false);
    return (true);
}

// Sprawdzam czy mam wymagana liczbe danych znakow. Sprawdzam rowniez
// czy nie ma znakow nie porzadanych.

void    check_characters(char **map)
{
    size_t  collectibles; // rzeczy do zbierania (min. 1)
    size_t  exits; // wyjscia (musi byc 1)
    size_t  players; // gracze (musi byc 1)
    short   x;
    short   y;

    collectibles = 0;
    exits = 0;
    players = 0;
    x = -1;
    while (++x, map[x]) // iteracja prze wiersze
    {
        y = -1;
        while (++y, map[x][y]) // iteracja przez kolumny (czyli przez znaki w danym wierszu)
        {
            if (!verify_characters(map[x][y], &collectibles, &exits, &players)) // sprawdzam dany znak z mapy z wymogami gry. Przekazuje adresy, aby moc zmieniac ich wartosc w nowej funkcji.
                error(map, "The map contains invalid characters");
        }
    }
    if (collectibles < 1)
        error(map, "Wrong number of collectibles! Must be at least 1.");
    if (exits != 1)
        error(map, "Wrong number of exits! There can only be 1.");
    if (players != 1)
        error(map, "Wrong number of players! There can only be 1.")
}