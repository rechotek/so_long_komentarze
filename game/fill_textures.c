/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:36:00 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 19:06:45 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Umieszcza dana teksture (obraz) w okreslonym miejscu w oknie gry. Aby to
// zrobic musialem wczesneij zainicjalizowac teksture, czyli zmienic ja z pliku
// na obraz w pliku start_game.
// Przyjmuje strukture "game", wskaznik "txt" do pliku z tekstura,
// oraz wspolrzedne "x" i "y", ktore odpowiadaja za miejsce na mapie.

static void	fill_texture(t_game game, void *txt, short x, short y)
{
	mlx_pu_image_to_window(game.mlx, game.window, txt, x, y);
}

// Ta funkcja wgrywa odpowiednia teksture dla gracza w zaleznosci od
// tego, w ktora strone sie rusza. Czyli w zaleznosci od tego jaki
// klawisz naciska.

static void	fill_player(t_game game, char key, short x, short y)
{
	if (key == 'w') // idzie w gore wiec widzimy plecy postaci
		fill_texture(game, game.txt.pb, x, y);
	if (key == 's') // idzie w dol wiec widzimy przod postaci
		fill_texture(game, game.txt.pd, x, y);
	if (key == 'a') // idzie w lewo wiec postac skierowana w lewo
		fill_texture(game, game.txt.pl, x, y);
	if (key == 'd') // idzie w prawo wiec postac skierowana w prawo
		fill_texture(game, game.txt.pr, x, y);
}

// Jest to glowna funkcja. Iteruje ona przez cala mape i umieszcza odpowiednie
// tekstury w oknie gry.
// Tekstury znajduja sie w odpowiednich zmiennych w strukturach (np. game.txt.a),
// bo zainicjowalem je w pliku start_game w funkcji init_textures 

void	fill_textures(t_game game, char key)
{
	short	x;
	short	y;

	x = 0;
	while (game.map[x])
	{
		y = 0;
		while (game.map[x][y])
		{
			if (game.map[x][y] == '0') // jesli na danym miejscu znajdzie '0' to wgra w to miejsce plik .a (puste pole) o wymiarach 50x50 pikseli
				fill_texture(game, game.txt.a, x * 50, y * 50);
			if (game.map[x][y] == '1') // jesli na danym miejscu znajdzie '1' to wgra w to miejsce plik .w (sciana) o wymiarach 50x50 pikseli
				fill_texture(game, game.txt.w, x * 50, y * 50);
			if (game.map[x][y] == 'C') // jesli na danym miejscu znajdzie 'C' to wgra w to miejsce plik .c (collectibles) o wymiarach 50x50 pikseli
				fill_texture(game, game.txt.c, x * 50, y * 50);
			if (game.map[x][y] == 'E') // jesli na danym miejscu znajdzie 'E' to wgra w to miejsce plik .e (wyjscie) o wymiarach 50x50 pikseli
				fill_texture(game, game.txt.e, x * 50, y * 50);
			if (game.map[x][y] == 'T') // jesli na danym miejscu znajdzie 'T' to wgra w to miejsce plik .t (wrog) o wymiarach 50x50 pikseli
				fill_texture(game, game.txt.t, x * 50, y * 50);
			if (game.map[x][y] == 'P') // jesli na danym miejscu znajdzie 'P' to wgra w to miejsce plik z postacia o wymiarach 50x50 pikseli. Ale widok postaci zmienia sie w zaleznosci od tego, w ktora strone idzie. Dlatego stworzylem dodatkowa funkcje, ktora uzaleznia wgrany plik od tego jaki przycisk nacisnalem. 
				fill_player(game, key, x * 50, y * 50);
			y++;
		}
		x++;
	}
}