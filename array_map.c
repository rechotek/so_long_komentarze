/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:04:35 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 18:32:54 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// przeksztalca mape w jeden, polaczony ciag znakow

static char *read_map(int fd)
{
    char    *str;
    char    *tmp;
    char    *line;

    str = get_next_line(fd); // odczytuje pierwsza linie mapy z pliku fd (czyli pliku gdzie jest zapisana mapa)
    if (!str) // jesli nie udalo sie odczytac linii (bo np. jej nie ma) to zwracam blad
        error(NULL, "Map file is empty");
    line = get_next_line(fd); // pobieram kolejna linie mapy z pliku fd
    while (line) // dopoki kolejna linia mapy istnieje
    {
        tmp = str;
        str = ft_strjoin(tmp, line); // za pomoca strjoin lacze tmp i line w jeden string
        free(line); // uwalniam pamiec dla line (juz jej nie potrzebuje, bo wykorzystalem ja w strjoin)
        free(tmp); // uwalniam pamiec dla tmp (juz jej nie potrzebuje, bo wykorzystalem ja w strjoin)
        line = get_next_line(fd); // pobieram kolejna linie mapy z pliku fd
    }
    return (str); // zwracam cala mape w postaci jednego stringa
}

// otwiera plik z mapa i odczytuje zawartosc. Na koniec zwraca tablice dwuwymiarowa, tablice z ciagami znakow, gdzie kazdy string odpowiada wierszowi mapy

char    **array_map(char *path)
{
    char    **map;
    char    *map_str;
    int     fd;

    fd = open(path, O_RDONLY); // open sluzy do otwierania plikow. path to sciezka do pliku, ktory chce otworzyc. O_RDONLY oznacza otwarcie pliku tylko do odczytu
    if (fd < 0) // error zostanie wywolany jak open zwroci wartosc mniejsza niz 0 (czyli blad)
        error(NULL, "Wrong file path");
    map_str = read_map(fd); // wykonujac read_map otrzymuje cala mape w 1 stringu (czyli wszystkie wiersze polaczone w 1 string)
    map = ft_split(map_str, '\n'); // za pomoca splita dziele string z map_str na czesci ktore oddziela '\n'. Dzieki temu w map otrzymam tablice ciagow znakow (stringow), gdzie kazdy string odpowiada wierszowi mapy.
    free(map_str); // uwalniam pamiec dla map_str. W funkcji read_map za pomoca ft_strjoin alokuje pamiec dla str. Nigdzie jej nie zwalniam dlatego wazne jest abym zrobil to teraz
    return (map); // map jest to tablica z ciagami znakow, gdzie kazdy ciag znakow odpowiada wierszowi mapy
}