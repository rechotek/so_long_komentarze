/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:40:53 by mrechuli          #+#    #+#             */
/*   Updated: 2024/05/28 18:31:58 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// flood_fill jest funkcja rekurencyjna, ktora "wypelnia" pola na dwuwymiarowej
// tablicy znakow reprezentujacych mape. Zaczynam od pozycji, w ktorej znajduje
// sie postac na poczatku gry. Sprawdzam czy ta pozycja spelnia jakis
// warunek z IF. Jesli nie to ustawiam wartosc miejsca gdzie teraz jestem na 'X'
// Nastepnie wywoluje rekurencyjnie funkcje flood_fill dla miejsca powyzej,
// ponizej, w lewo i w prawo od miejsca, w ktorym jestem i rowniez oznaczam pola
// za pomoca 'X'. Dzieki rekurencji funkcja wywoluje siebie tyle razy az
// zaznaczy na mapie 'X' kazde miejsce gdzie moze ruszyc sie postac.
// Zmienia na 'X' rowniez pola gdzie jest cos do zbierania ('C') oraz exit ('E')

static void	flood_fill(char **map, int height, int x, int y)
{
	size_t	width;

	width = map_width(map[0]);
	if (x < 0 || x >= height || y < 0 || y >= width // sprawdzam czy aktualna pozycja nie jest poza mapa, nie jest '1', 'X' lub 'T'
		|| map[x][y] == '1' || map[x][y] == 'X' || map[x][y] == 'T') // T to wrog
		return ;
	map[x][y] = 'X';
	flood_fill(map, height, x, y - 1); // lewo
	flood_fill(map, height, x, y + 1); // prawo
	flood_fill(map, height, x - 1, y); // gora
	flood_fill(map, height, x + 1, y); // dol
}

// tworze duplikat mapy, aby moc ja swobodnie edytowac nie zmieniajac oryginalnej

static char	**duplicate_map(char **map)
{
	char	**map_dup; // wskaznik do nowej, zduplikowanej tablicy
	short	x;

	map_dup = malloc(sizeof(char *) * (map_height(map) + 1)); // alokacja pamieci dla wskaznikow do wierszy nowej mapy; +1 dla NULL na koncu
	if (!map_dup)
		return (NULL);
	map_dup[map_height(map)] = NULL; // dodaje NULL na koncu nowo stworzonej tablicy, aby bylo wiadomo gdzie jest koniec; NULL jest na miejscu, ktore oblicza map_height, poniewaz wiersze tablicy zaczynaja sie od 0,a dlugosc liczymy od 1
	x = 0;
	while (map[x]) // iteruje po wierszach starej mapy
	{
		map_dup[x] = ft_strdup(map[x]); // kopiuje bierzcy wiersz orginalnej mapy (map[x]) za pomoca strdup do map_dup
		if (!map_dup[x]) // sprawdzam czy kopiowanie sie powiodlo...
		{
			free_map(map_dup); // .., jesli nie to zwalniam zaalkowana pamiec dla nowej mapy (map_dup)
			return (NULL); // zwracam NULL bo kopiowanie sie nie powiodlo
		}
		x++;
	}
	return (map_dup); // zwracam wskaznik do nowej, skopiowanej, mapy
}

// sprawdza czy jest mozliwosc ukonczenia mapy
// tworzy duplikat mapy
// znajduje pozycje, w ktorej na poczatku jest postac (find_gps)
// wszystki pola gdzie moze sie ludzik ruszyc (lacznie z C i E) sa zamieniane na X
// za pomoca is_all_collected sprawdzam czy wszystkie C i E zostaly "zebrane", czyli zamienione na X

void	check_way(char **map)
{
	char	**map_dup;
	short	p_pos[2];
	size_t	height;

	height = map_height(map);
	map_dup = duplicate_map(map); // tworze duplikat mapy
	if (!map_dup)
		error(map, "Allocation falied");
	find_gps(map_dup, p_pos, NULL); // okreslam miejsce gdzie znajduje sie postac na poczatku
	flood_fill(map_dup, height, p_pos[0], p_pos[1]); // wypelniam X-sami kazde miejsce gdzie moze wejsc postac
	if (!is_all_collected(map_dup)) // sprawdzam czy postac ma mozliwosc zebrania wszystkich C i E
	{
		free_map(map_dup);
		error(map, "map is not finishable");
	}
	free_map(map_dup);
}