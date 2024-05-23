/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:02:17 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 18:18:15 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int main(int argc, char *argv[])
{
    t_game  game;

    if (argc != 2) // sprawdzam czy podalem tylko 1 plik z mapa
        error(NULL, "You must enter only one map file");
    game.map = array_map(argv[1]); // zamienia mape z pliku w tablice ze stringami, ktore zawieraja wiersze mapy
    check_map(game.map); // sprawdza czy mapa jest prawidlowo zbudowana i czy jest mozliwe zebranie wszystkich przedmiotow i dojscie do wyjscia
    start_game(game); 
    free_map(game.map);
    return (0);
}