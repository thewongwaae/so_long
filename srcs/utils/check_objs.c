/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:24:49 by hwong             #+#    #+#             */
/*   Updated: 2023/02/19 23:09:24 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	restore(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '3')
				game->map[y][x] = '0';
			if (game->map[y][x] == '4')
				game->map[y][x] = 'C';
			if (game->map[y][x] == '5')
				game->map[y][x] = 'E';
			if (game->map[y][x] == '6')
				game->map[y][x] = '2';
			x++;
		}
		y++;
	}
}

static void	save_state(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		game->map[y][x] = '4';
	else if (game->map[y][x] == 'E')
		game->map[y][x] = '5';
	else if (game->map[y][x] == '2')
		game->map[y][x] = '6';
	else if (game->map[y][x] == '0')
		game->map[y][x] = '3';
}

static void	check_collect(t_game *game, int y, int x, int *c)
{
	if (game->tmp != *c)
		return ;
	if (y < 1 || x < 1 || game->size.y < y || game->size.x < x)
		return ;
	if ((game->map[y][x] >= '3' && game->map[y][x] <= '6')  || game->map[y][x] == '1' || game->map[y][x] == 'E')
		return ;
	if (game->map[y][x] == 'P')
	{
		(*c)++;
		return ;
	}
	save_state(game, y, x);
	check_collect(game, y - 1, x, c);
	check_collect(game, y + 1, x, c);
	check_collect(game, y, x - 1, c);
	check_collect(game, y, x + 1, c);
}

static void	check_enemy(t_game *game, int y, int x, int *e)
{
	if (*e > 0)
		return ;
	if (y < 1 || x < 1 || game->size.y < y || game->size.x < x)
		return ;
	if ((game->map[y][x] >= '3' && game->map[y][x] <= '6')  || game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'P')
	{
		(*e)++;
		return ;
	}
	save_state(game, y, x);
	check_enemy(game, y - 1, x, e);
	check_enemy(game, y + 1, x, e);
	check_enemy(game, y, x - 1, e);
	check_enemy(game, y, x + 1, e);
}

int	check_ce(t_game *game)
{
	int	y;
	int	x;
	int	c;
	int	e;

	y = -1;
	c = 0;
	e = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
			{
				game->tmp = c;
				check_collect(game, y, x, &c);
			}
			restore(game);
			if (game->map[y][x] == 'E')
				check_enemy(game, y, x, &e);
			restore(game);
		}
	}
	if (c != collect(game) || e != 1)
		return (1);
	return (0);
}
