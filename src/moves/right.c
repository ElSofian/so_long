/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:10 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/19 14:29:01 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game, int x, int y)
{
	char	tmp;
	
	if (game->map->map[game->player->y][game->player->x + 1] == '0')
	{
		tmp = game->map->map[game->player->y][game->player->x];
		game->map->map[game->player->y][game->player->x + 1] = 'P';
		game->map->map[game->player->y][game->player->x - 1] = tmp;
	} else if (game->map->map[game->player->y][game->player->x + 1] == 'C')
	{
		tmp = game->map->map[game->player->y][game->player->x];
		game->map->map[game->player->y][game->player->x + 1] = 'P';
		game->map->map[game->player->y][game->player->x - 1] = tmp;
		game->player->collectibles++;
	} else if (game->map->map[game->player->y][game->player->x + 1] == 'E')
	{
		tmp = game->map->map[game->player->y][game->player->x];
		game->map->map[game->player->y][game->player->x + 1] = 'P';
		game->map->map[game->player->y][game->player->x - 1] = tmp;
	}
}

void	right(t_game *game)
{
	char	tmp;

	if (!game->player
		|| !game->map->map[game->player->y][game->player->x + 1]
		|| game->map->map[game->player->y][game->player->x + 1] == '1')
		return ;
	game->player->moves++;
	game->player->direction = 'R';
	game->player->x++;
	move(game, game->player->x, game->player->y);
	ft_printf("Moves: %d (Player moved right)   |   Pos : %d / %d\n", game->player->moves, game->player->x, game->player->y);
}
