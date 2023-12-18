/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:58:51 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 14:24:35 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include "../mlx/mlx.h"

#ifndef PLAYER_NAME
#define PLAYER_NAME "Popol"
#endif

#ifndef WIDTH
#define WIDTH 1000
#endif

#ifndef HEIGHT
#define HEIGHT 400
#endif

#define ESCAPE 0xff1b
#define UP 0xff52
#define DOWN 0xff54
#define LEFT 0xff51
#define RIGHT 0xff53
#define W 0x0077
#define S 0x0073
#define A 0x0061
#define D 0x0064

typedef struct s_player
{
	int x;
	int y;
	int moves;
	int items;
	char *name;
} t_player;

typedef struct s_img
{
	int bits_per_pixel;
	int line_length;
	int endian;
	void *img;
	char *addr;
	char *wall;
	char *floor;
	char *collect;
	char *exit;
	char *player;
} t_img;

typedef struct s_map
{
	int width;
	int height;
	int collectibles_count;
	int exit_count;
	char *path;
	char *name;
	char **map;
	t_img img;
} t_map;

typedef struct s_game
{
	void *mlx;
	void *window;
	t_map *map;
	t_player *player;
} t_game;

// Main

void 	error(char *msg, t_game *game);
void 	initialize(t_game *game, char **map_file);
void 	close_window(t_game *game);
void 	open_window(t_game *game);
int		manage_keys(int key, t_game *game);
int		game_loop(t_game *game);

// Moves

void	up(t_player *player);
void	down(t_player *player);
void	left(t_player *player);
void	right(t_player *player);

// Map

int		create_map(t_game *game);
void	check(t_game *game);
void	print_map(t_game *game);

// Utils

char	**split(char *s, int width, int height);

#endif