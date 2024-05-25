#include "../so_long.h"

void	move_player(t_game *game, short x_off, short y_off, char key) // off pochodzi od offset. W tym kontekscie oznacza odsuniecie od od punktu odniesienia
{

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