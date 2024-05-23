/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:01:15 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 16:01:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// uruchamiam wszystkie funkcje, ktore sa niezbedne do rozpoczecia gry

void	start_game(t_game game)
{
	game.mlx = mlx_init(); // inicjalizuje polacze z serwerem X Window System. Zwraca wskaznik do MLX, ktory jest przechowywany w game.mlx. Dzieki temu mam dostep do biblioteki minilibx i moge ja wykorzystywac
	game.width = map_width(game.map[0]); // oblicza szerokosc mapy i przechowuje ja w strukturze t_game
	game.height = map_height(game.map); // oblicza wysokosc mapy i przechowuje ja w strukturze t_game
	game.window = mlx_new_window(game.mlx, game.width * 50, game.height * 50,
		"so_long"); // tworzy nowe okno o obliczonych wymiarach. Jest "* 50", poniewaz bierzemy obliczona szerokosc/wys i musimy ja pomnozyc przez 50 bo to wymiar tekstur (50x50 w pikselach), "so_long" to nazwa okna
	find_gps(game.map, game.p_pos, game.e_pos); // znajduje pozycje, w ktorej jest wyjscie i gracz na poczatku
	init_textures(&game); // ta funkcja inicjalizuje tekstury. Odnosi sie ona do adresu &game, poniewaz tamsa zapisane niezbedne dane do inicjalizacji tekstur
	fill_textures(game, 'w'); // ta funkcja wypelnia mape zainicjalizowanymi wyzej teksturami. Jako klucz jest podany 'w', poniewaz pierwszym polem do wypelnienia jest sciana, ktora oznaczylem jako 'w'
	
}