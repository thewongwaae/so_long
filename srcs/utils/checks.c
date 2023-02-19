/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:13:48 by hwong             #+#    #+#             */
/*   Updated: 2023/02/19 19:28:55 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	mapsize(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
			x++;
		y++;
	}
	if (y == x)
		return (1);
	game->size.x = x;
	game->size.y = y;
	return (0);
}

static int	validity(t_game *game)
{
	game->check.collect = 0;
	game->check.enemy = 0;
	game->check.player = 0;
	game->check.size.y = 0;
	while (game->map[game->check.size.y])
	{
		game->check.size.x = 0;
		while (game->map[game->check.size.y][game->check.size.x])
		{
			if (game->map[game->check.size.y][game->check.size.x] == 'C')
				game->check.collect++;
			if (game->map[game->check.size.y][game->check.size.x] == 'P')
				game->check.player++;
			if (game->map[game->check.size.y][game->check.size.x] == 'E')
				game->check.enemy++;
			game->check.size.x++;
		}
		game->check.size.y++;
	}
	if (game->check.collect < 1 || game->check.player != 1 || game->check.enemy != 1)
		return (1);
	return (0);
}

int	checks(t_game *game, char **av)
{
	if (mapsize(game) == 1)
		return (1);
	if (validity(game) == 1)
		return (1);
	if (rowwall(game) == 1)
		return (1);
	if (colwall(game) == 1)
		return (1);
	if (valid(game) == 1)
		return (1);
	if (checkp(game) == 1)
		return (1);
	if (checkav(av) == 1)
		return (1);
	return (0);
}
