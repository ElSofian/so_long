/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:58:51 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/16 14:04:03 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# ifndef PLAYER_NAME
#  define PLAYER_NAME "Popol"
# endif

# define ESCAPE 17

typedef struct s_player {
	int		x;
	int		y;
	int		moves;
	int		items;
	char	*name;
}			t_player;

typedef struct s_collectible {
	int	x;
	int	y;
	int	amount;
}			t_collectible;

typedef struct s_exit {
	int	x;
	int	y;
}			t_exit;

typedef struct s_map {
	int		width;
	int		height;
	int		collectibles_count;
	int		exit_count;
	char	*name;
}			t_map;

typedef struct s_game {
	void		*mlx;
	void		*window;
	t_map		*map;
	t_player	*player;
}				t_game;

// Main

void	error(char *msg, t_game *game);
void	initialize(t_game *game);
void	close_window(t_game *game);
void	open_window(t_game *game);

#endif