/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:32:39 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/17 17:24:33 by soelalou         ###   ########.fr       */
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
	player->x = 50;
	player->y = 50;
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
	game->map = map;
	create_map(game);
	// initialize_map_content(map, game);
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
		return ;
	}
	game->mlx = mlx;
	initialize_map(game, map_file);
	// initialize_image(game);
	initialize_player(game);
	open_window(game);
	initialize_hooks(game);
	mlx_loop(game->mlx);
}
