/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:48:41 by hwong             #+#    #+#             */
/*   Updated: 2023/02/19 23:08:22 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
	t_vec		playerpos;
	t_check		check;
	t_window	window;
	t_sprites	sprites;
	int			steps;
	int			tmp;
}				t_game;

/* GAME */
// main
int		collect(t_game *game);
// render
void	sprites(t_game *game);
void	render(char **map, t_game *game);
int		refresh(t_game *game);
// move
int		mup(t_game *game);
int		mdown(t_game *game);
int		mleft(t_game *game);
int		mright(t_game *game);

/* UTILS */
// checks
int		check_av(char **av);
int		check_ce(t_game *game);
int		check_player(t_game *game);
int		checks(t_game *game, char **av);
// strings
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_itoa(int n);
// gnl
char	*ft_join(char *buff, char *buffer);
char	*check_ch(char *str, int sep);
char	*get_next_line(int fd);
// split
char	**ft_split(char const *s, char c);

#endif