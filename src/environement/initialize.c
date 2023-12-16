/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:32:39 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/16 14:04:45 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_player(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		ft_printf("Error:\n%s\n", "An error occured while initializing player");
		return ;
	}
	player->x = 50;
	player->y = 50;
	player->moves = 0;
	player->items = 0;
	player->name = ft_strdup(PLAYER_NAME);
	if (!player->name)
	{
		ft_printf("Error:\n%s\n", "An error occured while initializing player name");
		return ;
	}
	game->player = player;
}

static void	initialize_map(t_game *game)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error:\n%s\n", "An error occured while initializing map");
		return ;
	}
	map->width = 400;
	map->height = 400;
	map->collectibles_count = 0;
	map->exit_count = 0;
	map->name = ft_strdup("So_long");
	if (!map->name)
	{
		ft_printf("Error:\n%s\n", "An error occured while initializing map name");
		return ;
	}
	game->map = map;
}

void	initialize(t_game *game)
{
	void	*mlx;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		error("An error occured while initializing game", game);
		return ;
	}
	mlx = mlx_init();
	if (!mlx)
	{
		error("An error occured while initializing mlx", game);
		return ;
	}
	initialize_map(game);
	initialize_player(game);
	open_window(game);
	mlx_loop(game->mlx);
}