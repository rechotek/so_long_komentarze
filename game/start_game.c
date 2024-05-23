/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:01:15 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 18:54:13 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Ta funkcja sluzy do inicjalizacji tekstur uzywanych w grze.
// Kazde wywolanie mlx_xpm_file_to_image przyjmuje 4 argumenty:
// - game->mlx - wskaznik to struktury zawierajacej biblioteke MinilibX
// - "textures/0.xpm" - sciezka do pliku z tekstura
// - wskaznik do szerokosci obrazu
// - wskaznik do wysokosci obrazu
// To wywolanie:
// - laduje obraz z pliku "textures/0.xpm"
// - przypisuje zaladowany obraz do pola 'a' struktury 'txt' w strukturze 'game'
// - aktualizuje wartosc game->width i game->height do szerokosci i wysokosci zaladowanego obrazu (to znaczy, ze funkja odczytuje ta szerokosc i wysokosc z obrazu i przypisuje ja do odpowiednicj wskaznikow)

static void	init_textures(t_game *game)
{
	game->txt.a = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm", &(game->width), &(game->height));
	game->txt.w = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm", &(game->width), &(game->height));
	game->txt.c = mlx_xpm_file_to_image(game->mlx, "textures/c.xpm", &(game->width), &(game->height));
	game->txt.e = mlx_xpm_file_to_image(game->mlx, "textures/e.xpm", &(game->width), &(game->height));
	game->txt.t = mlx_xpm_file_to_image(game->mlx, "textures/t.xpm", &(game->width), &(game->height));
	game->txt.pb = mlx_xpm_file_to_image(game->mlx, "textures/pb.xpm", &(game->width), &(game->height));
	game->txt.pd = mlx_xpm_file_to_image(game->mlx, "textures/pd.xpm", &(game->width), &(game->height));
	game->txt.pl = mlx_xpm_file_to_image(game->mlx, "textures/pl.xpm", &(game->width), &(game->height));
	game->txt.pr = mlx_xpm_file_to_image(game->mlx, "textures/pr.xpm", &(game->width), &(game->height));

}

// Uruchamiam wszystkie funkcje, ktore sa niezbedne do rozpoczecia gry

void	start_game(t_game game) // game jest kopia struktury t_game
{
	game.mlx = mlx_init(); // inicjalizuje polaczenie z serwerem X Window System. Zwraca wskaznik do MLX, ktory jest przechowywany w game.mlx. Dzieki temu mam dostep do biblioteki minilibx i moge ja wykorzystywac
	game.width = map_width(game.map[0]); // oblicza szerokosc mapy i przechowuje ja w strukturze t_game
	game.height = map_height(game.map); // oblicza wysokosc mapy i przechowuje ja w strukturze t_game
	game.window = mlx_new_window(game.mlx, game.width * 50, game.height * 50,
		"so_long"); // tworzy nowe okno o obliczonych wymiarach. Jest "* 50", poniewaz bierzemy obliczona szerokosc/wys i musimy ja pomnozyc przez 50 bo to wymiar tekstur (50x50 w pikselach), "so_long" to nazwa okna
	find_gps(game.map, game.p_pos, game.e_pos); // znajduje pozycje, w ktorej jest wyjscie i gracz na poczatku
	init_textures(&game); // ta funkcja inicjalizuje tekstury. Odnosi sie ona do adresu &game, poniewaz tam sa zapisane niezbedne dane do inicjalizacji tekstur
	fill_textures(game, 'w'); // ta funkcja wypelnia mape zainicjalizowanymi wyzej teksturami. Jako klucz jest podany 'w', poniewaz pierwszym polem do wypelnienia jest sciana, ktora oznaczylem jako 'w'
	
}