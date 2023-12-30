/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:32:39 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 12:56:40 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_ghosts(t_game *game)
{
	int		x;
	int		y;
	t_ghost	*ghost;

	game->ghost = NULL;
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < (game->map->width / game->map->height))
		{
			if (game->map->map[y][x] != 'G')
				continue ;
			ghost = (t_ghost *)malloc(sizeof(t_ghost));
			if (!ghost)
				return (error("An error while initializing ghosts.", game));
			ghost->x = x;
			ghost->y = y;
			ghost->moves = 0;
			ghost->direction = 'R';
			ghost->next = NULL;
			lstadd_back(&game->ghost, ghost);
		}
	}
}

static void	initialize_player(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		error("An error occured while initializing player", game);
		return ;
	}
	player->x = game->map->player[0];
	player->y = game->map->player[1];
	player->moves = 0;
	player->collectibles = 0;
	player->direction = 'N';
	player->name = ft_strdup(PLAYER_NAME);
	if (!player->name)
	{
		error("An error occured while initializing player name", game);
		return ;
	}
	game->player = player;
}

static int	initialize_image(t_game *game)
{
	int	size;

	size = SIZE;
	game->map->img.img = mlx_new_image(game->mlx,
			(game->map->width / game->map->height) * SIZE,
			game->map->height * SIZE);
	game->map->img.addr = mlx_get_data_addr(game->map->img.img,
			&game->map->img.bits_per_pixel,
			&game->map->img.line_length, &game->map->img.endian);
	game->map->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Other/Walls/black.xpm", &size, &size);
	game->map->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Other/Walls/wall.xpm", &size, &size);
	game->map->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Other/Pacdots/pacdot_food.xpm", &size, &size);
	game->map->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Other/Portal/portal.xpm", &size, &size);
	game->map->img.pause = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Other/Logo/logo.xpm", &size, &size);
	initialize_player_anims(game);
	initialize_ghost_anims(game);
	return (0);
}

static void	initialize_map(t_game *game, char **map_file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error("An error occured while initializing map", game);
	map->path = ft_strdup(*map_file);
	if (!map->path)
		error("An error occured while initializing map path", game);
	free(*map_file);
	map->name = ft_strdup(ft_strrchr(map->path, '/') + 1);
	if (!map->name)
		error("An error occured while initializing map name", game);
	game->map = map;
	create_map(game);
	check(game);
}

void	initialize(t_game *game, char **map_file)
{
	void	*mlx;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error("An error occured while initializing game", NULL);
	mlx = mlx_init();
	if (!mlx)
	{
		free(game);
		error("An error occured while initializing mlx", NULL);
	}
	game->mlx = mlx;
	game->paused = false;
	initialize_map(game, map_file);
	initialize_ghosts(game);
	initialize_player(game);
	open_window(game);
	initialize_image(game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_hook(game->window, 2, 1L << 0, manage_keys, game);
	render_map(game);
	mlx_loop_hook(game->mlx, ghosts, game);
	mlx_loop(game->mlx);
}
