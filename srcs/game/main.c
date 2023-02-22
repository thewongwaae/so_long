/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:47:58 by hwong             #+#    #+#             */
/*   Updated: 2023/02/22 15:41:25 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect(t_game *game)
{
	int	y;
	int	x;
	int	collect;

	collect = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				collect++;
		}
	}
	return (collect);
}

static int	endgame(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static int	move(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		mup(game);
	else if (keycode == 0 || keycode == 123)
		mleft(game);
	else if (keycode == 1 || keycode == 125)
		mdown(game);
	else if (keycode == 2 || keycode == 124)
		mright(game);
	else if (keycode == 53)
		endgame(game);
	return (0);
}

static char	**parse_map(char *mapfile)
{
	char	*line;
	char	*out;
	int		fd;

	line = "";
	out = ft_strdup("");
	fd = open(mapfile, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL || line[0] == '\n')
			break ;
		out = ft_free(out, line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (ft_split(out, '\n'));
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map = parse_map(av[1]);
		if (checks(&game, av) == 1)
			return (write(2, "Map file provided was invalid.\n", 31));
		game.window.fps = 0;
		game.steps = 0;
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.size.x,
				game.size.y, "so_long");
		sprites(&game);
		render(game.map, &game);
		mlx_key_hook(game.win, move, &game);
		mlx_hook(game.win, 17, (1L << 0), endgame, &game);
		mlx_loop_hook(game.mlx, refresh, &game);
		mlx_loop(game.mlx);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
