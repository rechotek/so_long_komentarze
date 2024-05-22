/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:07:56 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 17:33:30 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/printf/libftprintf.h"
# include "libs/minilibx/mlx.h"
# include <stdbool.h>

// nazwy pol w strukturze nie moga sie zaczynac od cyfr, dlatego zmienilem 0 -> a i 1 -> w

typedef struct s_txt
{
	void	*a; // puste pole po ktorym mozna chodzic
	void	*w; // sciana (od wall)
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
	void	*win;
	int		w; // width??
	int		h; // height?
	short	p_pos[2]; // [2] oznacza ze jest to tablica z 2 argumentami; przechowuje polozenie wyjscia
	short	e_pos[2]; // przechowuje polozenie wyjscia
	short	**m_pos;
	t_txt	txt;
}   t_game;

