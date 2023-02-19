/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:48:41 by hwong             #+#    #+#             */
/*   Updated: 2023/02/19 19:28:45 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

typedef struct	s_vec
{
	int	x;
	int	y;
}		t_vec;

typedef struct	s_window
{
	t_vec	size;
	int		fps;
	void	*enemy;
	void	*exit;
}			t_window;

typedef struct s_check
{
	t_vec	size;
	int		collect;
	int		enemy;
	int		player;
}			t_check;

typedef struct s_sprites
{
	void	*wall;
	void	*collect;
	void	*player;
	void	*enemy1;
	void	*enemy2;
	void	*white;
	void	*exit1;
	void	*exit2;
}			t_sprites;

typedef struct	s_game
{
	char		**map;
	void		*mlx;
	void		*win;
	t_vec		size;
	t_check		check;
	t_window	window;
	t_sprites	sprites;
	int			steps;
}				t_game;

/* GAME */
// main

// render
void	sprites(t_game *game);
void	render(char **map, t_game *game);

/* UTILS */
// checks
int		checks(t_game *game, char **av);
// strings
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
// gnl
char	*get_next_line(int fd);
char	*check_c(char *str, int sep);
