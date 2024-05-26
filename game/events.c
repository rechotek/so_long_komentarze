#include "../so_long.h"

// display_moves sluzy do wyswietlenia ilosci ruchow ktore wykonala postac, w oknie gry

static void	display_moves(t_game *game, short moves)
{
	char	*str;

	str = ft_itoa(moves); // zamienia liczbe "moves" na string' czyli zamieni liczbe 42 na string 42
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFFFFFFFF, "Moves: "); // napisze "Moves: " w oknie (game->window), w kolorze bialym (0xFFFFFFF), na pozycji x=10 i y=20
	mlx_string_put(game->mlx, game->window, 70, 20, 0xFFFFFFFF, str); // dopisze do "Moves: " liczbe z wartosci "str" (juz w postaci stringa), w kolorze bialym, na pozycji x=70 i y=20
	free(str); // uwalniam pamiec dla str, poniewaz wczesniej alokuje ja w funkcji ft_itoa
}

// ta funkcja jest odpowiedzialna za przesuwanie gracza na mapie gry i aktualizowanie mapy
// przyjmuje wskaznik do struktury game, gdzie sa niezbedne informacje
// przesuniecie w kierunku "x" oraz "y"
// symbol z klawiatury, po ktorego nacisnieciu wykonuje sie akcja

void	move_player(t_game *game, short x_off, short y_off, char key) // off pochodzi od offset. W tym kontekscie oznacza odsuniecie od punktu odniesienia
{
	static short	moves = 0; // jest static poniewaz chcemy aby liczba ruchow byla aktualizowana przy kazdym wywolaniu funkcji
	short			new_row; // nowy rzad 
	short			new_col; // nowa kolumna

	new_row = game->p_pos[0] + x_off; // nowe polozenie postaci na osi x (czyli rzad mapy w ktorym sie znajduje po wykonaniu ruchu)
	new_col = game->p_pos[1] + y_off; // nowe polozenie postaci na osi y (czyli kolumna mapy w ktorej sie znajduje po wykonaniu ruchu)
	if (game->map[new_row][new_col] == '1') // sprawdzenie czy nowa pozycja gracza znajduje sie na planszy, po ktorej mozna sie poruszac; "1" oznacza sciane, czyli miejsce w ktore nie da sie wejsc
		return ; // nie mozna zrobic takiego ruchu wiec przerywam dzialanie funkcji i natychmiast z niej wychodze
	if (game->map[new_row][new_col] == 'T') // jesli nowa pozycja jest miejscem gdzie stoi wrog "M" ...
		close_game(game); // ... to zamykamy gre bo zginelismy
	moves++; // zliczam liczbe ruchow; w tym miejscu kodu, poniewaz nie chce jako ruch liczyc wejscia w sciane lub wroga
	if (game->map) // jesli mapa istnieje ...
		game->map[new_row][new_col] = 'P'; // ... to aktualizuje pozycje 'P' ustawiajac ja na nowe wspolrzedne
	if (new_row == game->e_pos[0] && new_col == game->e_pos[1]) // jesli pozycja gracza jest taka sama jak pozycja wyjscia ...
		if (is_all_collected(game->map)) // ... to jesli zebralismy wszystkie przedmioty ...
			close_game(game); // ... to zamykamy gre
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1]) // jesli pozycja gracza, z ktorej wyszedl (czyli jakby przed ruchem, stara pozycja), znajduje sie na pozycji wyjscia ...
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E'; // ... to ustawiam ta pozycje na mapie na 'E'
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0'; // ... w przeciwnym wypadku ustawiam ta pozycje na '0'; wtedy pozostawie '0' nadal '0', a jak zbiore 'C' to pozostawie je '0'
	game->p_pos[0] = new_row; // uaktualniam pozycje gracza (dopiero teraz, zwroc na to uwage w kodzie!)
	game->p_pos[1] = new_col;
	fill_textures(*game, key); // nowe zaladowanie tekstur (bo mapa sie zmienila)
	display_moves(game, moves); // wyswietlenie ruchow
}

// close_game odpowiada za zamkniecie okna z gra i zakonczenie dzialania programu
// po zamknieciu okna zwalniana jest pamiec i program konczy dzialanie

void	close_game(t_game *game)
{
	mlx_destroy_image(gane->mlx, game->txt.a); // mlx_destroy_image niszczy (usuwa) tekstury zaladowane do pamieci. Funkcja usuwa obrazy zaladowane do wskaznika
	mlx_destroy_image(gane->mlx, game->txt.w);
	mlx_destroy_image(gane->mlx, game->txt.c);
	mlx_destroy_image(gane->mlx, game->txt.e);
	mlx_destroy_image(gane->mlx, game->txt.pb);
	mlx_destroy_image(gane->mlx, game->txt.pd);
	mlx_destroy_image(gane->mlx, game->txt.pl);
	mlx_destroy_image(gane->mlx, game->txt.pr);
	mlx_destroy_image(gane->mlx, game->txt.t);
	mlx_destroy_window(game->mlx, game->window); // niszczy (zamyka) okno utworzone przez minilibX
	mlx_destroy_display(game->mlx); // zamyka wswietlacz w systemach UNIX. Jest uzywana do zwalniania zasobow zwiazanych z wyswietlaczem
	free(game->mlx); // uwalnia pamiec zaalokowana dla game->mlx
	free_map(game->map);
	exit(0);
}