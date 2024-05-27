/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:07:56 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 19:14:40 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/minilibx/mlx.h"
# include <stdbool.h>
# include <fcntl.h>

// nazwy pol w strukturze nie moga sie zaczynac od cyfr, dlatego zmienilem 0 -> a i 1 -> w

typedef struct s_txt
{
	void	*a; // puste pole po ktorym mozna chodzic (0)
	void	*w; // sciana (od wall) (1)
	void	*c; // cos do zbierania
	void	*e; // wyjscie
	void	*pb; // postac tylem (jak idzie do gory)
	void	*pd; // postac przodem (jak idze w dol)
	void	*pl; // postac w lewo
	void	*pr; // postac w prawo
	void	*t; // wrog/przeszkoda
}   t_txt;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	short	p_pos[2]; // [2] oznacza ze jest to tablica z 2 argumentami; przechowuje polozenie wyjscia
	short	e_pos[2]; // przechowuje polozenie wyjscia
	short	**m_pos;
	t_txt	txt;
}   t_game;

void	error(char **map, char *msg);
void	free_map(char **map);
char    **array_map(char *path);
void	check_map(char **map);
void	check_border(char **map);
void    check_characters(char **map);
void	check_rectangular(char **map);
void	check_way(char **map);
size_t	map_width(char *map);
size_t	map_height(char **map);
void	find_gps(char **map, short *p_pos, short *e_pos);
bool	is_all_collected(char **map);
void	fill_textures(t_game game, char key);
void	move_player(t_game *game, short x_off, short y_off, char key);
int		close_game(t_game *game);
void	start_game(t_game game);

#endif