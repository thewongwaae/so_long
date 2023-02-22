/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:56:53 by hwong             #+#    #+#             */
/*   Updated: 2023/02/22 15:42:17 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_pos(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->playerpos.y = y;
				game->playerpos.x = x;
				return ;
			}
		}
	}
}

int	mup(t_game *game)
{
	get_pos(game);
	if (game->map[game->playerpos.y - 1][game->playerpos.x] == '1')
		return (0);
	if (game->map[game->playerpos.y - 1][game->playerpos.x] == 'E'
			&& collect(game) > 0)
		return (0);
	if (game->map[game->playerpos.y - 1][game->playerpos.x] == '2')
	{
		write(2, "YOU DIED !\n", 11);
		exit (-1);
	}
	if (game->map[game->playerpos.y - 1][game->playerpos.x] == 'E'
			&& collect(game) == 0)
	{
		write(1, "YOU WIN !\n", 10);
		exit (0);
	}
	game->map[game->playerpos.y][game->playerpos.x] = '0';
	game->map[game->playerpos.y - 1][game->playerpos.x] = 'P';
	if (collect(game) == 0)
		game->window.exit = game->sprites.exit2;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	return (0);
}

int	mdown(t_game *game)
{
	get_pos(game);
	if (game->map[game->playerpos.y + 1][game->playerpos.x] == '1')
		return (0);
	if (game->map[game->playerpos.y + 1][game->playerpos.x] == 'E'
			&& collect(game) > 0)
		return (0);
	if (game->map[game->playerpos.y + 1][game->playerpos.x] == '2')
	{
		write(2, "YOU DIED !\n", 11);
		exit (-1);
	}
	if (game->map[game->playerpos.y + 1][game->playerpos.x] == 'E'
			&& collect(game) == 0)
	{
		write(1, "YOU WIN !\n", 10);
		exit (0);
	}
	game->map[game->playerpos.y][game->playerpos.x] = '0';
	game->map[game->playerpos.y + 1][game->playerpos.x] = 'P';
	if (collect(game) == 0)
		game->window.exit = game->sprites.exit2;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	return (0);
}

int	mleft(t_game *game)
{
	get_pos(game);
	if (game->map[game->playerpos.y][game->playerpos.x - 1] == '1')
		return (0);
	if (game->map[game->playerpos.y][game->playerpos.x - 1] == 'E'
			&& collect(game) > 0)
		return (0);
	if (game->map[game->playerpos.y][game->playerpos.x - 1] == '2')
	{
		write(2, "YOU DIED !\n", 11);
		exit (-1);
	}
	if (game->map[game->playerpos.y][game->playerpos.x - 1] == 'E'
			&& collect(game) == 0)
	{
		write(1, "YOU WIN !\n", 10);
		exit (0);
	}
	game->map[game->playerpos.y][game->playerpos.x] = '0';
	game->map[game->playerpos.y][game->playerpos.x - 1] = 'P';
	if (collect(game) == 0)
		game->window.exit = game->sprites.exit2;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	return (0);
}

int	mright(t_game *game)
{
	get_pos(game);
	if (game->map[game->playerpos.y][game->playerpos.x + 1] == '1')
		return (0);
	if (game->map[game->playerpos.y][game->playerpos.x + 1] == 'E'
			&& collect(game) > 0)
		return (0);
	if (game->map[game->playerpos.y][game->playerpos.x + 1] == '2')
	{
		write(2, "YOU DIED !\n", 11);
		exit (-1);
	}
	if (game->map[game->playerpos.y][game->playerpos.x + 1] == 'E'
			&& collect(game) == 0)
	{
		write(1, "YOU WIN !\n", 10);
		exit (0);
	}
	game->map[game->playerpos.y][game->playerpos.x] = '0';
	game->map[game->playerpos.y][game->playerpos.x + 1] = 'P';
	if (collect(game) == 0)
		game->window.exit = game->sprites.exit2;
	game->steps++;
	mlx_clear_window(game->mlx, game->win);
	render(game->map, game);
	return (0);
}
