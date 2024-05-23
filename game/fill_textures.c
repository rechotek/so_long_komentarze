/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:36:00 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 15:36:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill_texture(t_game game, void *txt, short x, short y)
{
	mlx_pu_image_to_window(game.mlx, game.win, txt, x, y);
}

static void	fill_player(t_game game, char key, short x, short y)
{
	if (key == 'w')
		fill_texture(game, game.txt.pb, x, y);
	if (key == 's')
		fill_texture(game, game.txt.pd, x, y);
	if (key == 'a')
		fill_texture(game, game.txt.pl, x, y);
	if (key == 'd')
		fill_texture(game, game.txt.pr, x, y);
}

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
			if (game.map[x][y] == '0')
				fill_texture(game, game.txt.a, x * 50, y * 50);
			if (game.map[x][y] == '1')
				fill_texture(game, game.txt.w, x * 50, y * 50);
			if (game.map[x][y] == 'C')
				fill_texture(game, game.txt.c, x * 50, y * 50);
			if (game.map[x][y] == 'E')
				fill_texture(game, game.txt.e, x * 50, y * 50);
			if (game.map[x][y] == 'T')
				fill_texture(game, game.txt.t, x * 50, y * 50);
			if (game.map[x][y] == 'P')
				fill_player(game, key, x * 50, y * 50);
			y++;
		}
		x++;
	}
}