/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:32:39 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 13:46:43 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_player(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		error("An error occured while initializing player", game);
		return ;
	}
	player->x = 0;
	player->y = 0;
	player->moves = 0;
	player->items = 0;
	player->name = NULL;
	player->name = ft_strdup(PLAYER_NAME);
	if (!player->name)
	{
		error("An error occured while initializing player name", game);
		return ;
	}
	game->player = player;
}

static void	initialize_image(t_game *game)
{
	game->map->img.img = mlx_new_image(game->mlx, game->map->width * 64,
			game->map->height * 64);
	game->map->img.addr = mlx_get_data_addr(game->map->img.img,
			&game->map->img.bits_per_pixel,
			&game->map->img.line_length, &game->map->img.endian);
}

static void	initialize_map(t_game *game, char **map_file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error("An error occured while initializing map", game);
	map->collectibles_count = 0;
	map->exit_count = 0;
	map->path = NULL;
	map->path = ft_strdup(*map_file);
	if (!map->path)
		error("An error occured while initializing map path", game);
	free(*map_file);
	map->name = NULL;
	map->name = ft_strdup(ft_strrchr(map->path, '/') + 1);
	if (!map->name)
		error("An error occured while initializing map name", game);
	map->map = NULL;
	game->map = map;
	create_map(game);
	check(game);
}

static void	initialize_hooks(t_game *game)
{
	mlx_key_hook(game->window, manage_keys, game);
	mlx_loop_hook(game->mlx, game_loop, game);
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
	initialize_map(game, map_file);
	initialize_player(game);
	open_window(game);
	initialize_image(game);
	initialize_hooks(game);
	mlx_loop(game->mlx);
}
