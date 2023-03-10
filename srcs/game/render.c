/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:38:01 by hwong             #+#    #+#             */
/*   Updated: 2023/02/22 16:50:30 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	refresh(t_game *game)
{
	if (game->window.fps == 5000)
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->window.enemy == game->sprites.enemy1)
			game->window.enemy = game->sprites.enemy2;
		else
			game->window.enemy = game->sprites.enemy1;
		game->window.fps = 0;
		render(game->map, game);
	}
	else
		game->window.fps++;
	return (0);
}

void	sprites(t_game *game)
{
	int	x;
	int	y;

	game->sprites.wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &x, &y);
	game->sprites.collect = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect.xpm", &x, &y);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &x, &y);
	game->sprites.exit1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit1.xpm", &x, &y);
	game->sprites.exit2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit2.xpm", &x, &y);
	game->sprites.enemy1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy1.xpm", &x, &y);
	game->sprites.enemy2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy2.xpm", &x, &y);
	game->window.enemy = game->sprites.enemy1;
	game->window.exit = game->sprites.exit1;
}

static void	show_steps(t_game *game)
{
	char	*num;
	char	*out;

	num = ft_itoa(game->steps);
	out = ft_strjoin("STEPS : ", num);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFF, out);
	free(num);
	free(out);
}

// image placement issue here, use 2 new ints to leave x and y unchanged
void	render(char **map, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.wall, x * 50, y * 40);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.collect, x * 50, y * 40);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprites.player, x * 50, y * 40);
			else if (map[y][x] == '2')
				mlx_put_image_to_window(game->mlx, game->win,
					game->window.enemy, x * 50, y * 40);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->window.exit, x * 50, y * 40);
		}
	}
	show_steps(game);
}
