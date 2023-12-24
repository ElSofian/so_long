/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:58:51 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 09:39:48 by soelalou         ###   ########.fr       */
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
# define PLAYER_NAME "Popol"
#endif

#ifndef SIZE
# define SIZE 32
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
#define R 0x0072

typedef struct s_player
{
	int x;
	int y;
	int moves;
	int collectibles;
	char direction;
	char *name;
} t_player;

typedef struct s_img
{
	int bits_per_pixel;
	int line_length;
	int endian;
	void *img;
	char *addr;
	void *wall;
	void *floor;
	void *collectible;
	void *exit;
	void *player_up;
	void *player_down;
	void *player_right;
	void *player_left;
} t_img;

typedef struct s_map
{
	int width;
	int height;
	int	collectibles;
	int	exit_pos[2];
	int	player_pos[2];
	int	**collectibles_pos;
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

void	error_map(char *msg, t_game *game);
void 	error(char *msg, t_game *game);
void 	initialize(t_game *game, char **map_file);
int 	close_window(t_game *game);
void 	open_window(t_game *game);
int		manage_keys(int key, t_game *game);

// Moves

void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);

// Map

int		create_map(t_game *game);
int		render_elements(t_game *game);
int		render_map(t_game *game);
void	check(t_game *game);
void	print_image(t_game *game, void *img, int x, int y);

// Utils

int		open_file(t_game *game);
void 	initialize_player_animation(t_game *game, int size);
void	free_int_tab(t_game *game, int **tab);
char	**split(char *s, int width, int height);

#endif