/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:36:44 by hwong             #+#    #+#             */
/*   Updated: 2023/02/21 13:14:05 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_av(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	i--;
	if (av[1][i--] == 'r')
		if (av[1][i--] == 'e')
			if (av[1][i] == 'b')
				return (0);
	return (1);
}

int	check_player(t_game *game)
{
	int	y;
	int	x;
	int	p;

	y = -1;
	p = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == 'P')
				p++;
	}
	if (p == 1)
		return (0);
	return (1);
}
