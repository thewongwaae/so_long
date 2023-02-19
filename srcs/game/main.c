/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:47:58 by hwong             #+#    #+#             */
/*   Updated: 2023/02/19 19:22:08 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map = parse_map(av[1]);
		if (checks(&game, av) == 1)
			return (write(2, "Map file provided was invalid.\n", 32));
		game.window.fps = 0;
		game.steps = 0;
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
		imange
	}
}