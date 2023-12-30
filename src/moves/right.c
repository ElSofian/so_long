/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:10 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 12:41:35 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game)
{
	char	tmp;

	if ((game->map->map[game->player->y][game->player->x + 1] == 'E'
		&& game->player->collectibles == game->map->collectibles)
		|| game->map->map[game->player->y][game->player->x + 1] == 'G')
	{
		if (game->map->map[game->player->y][game->player->x + 1] == 'G')
			send_message(game, false);
		else
			send_message(game, true);
		close_window(game);
	}
	if (game->map->map[game->player->y][game->player->x + 1] == 'C')
	{
		tmp = '0';
		game->player->collectibles++;
		if (game->player->collectibles == game->map->collectibles)
			game->map->map[game->map->exit[1]][game->map->exit[0]]
				= 'E';
	}
	else
		tmp = game->map->map[game->player->y][game->player->x + 1];
	game->map->map[game->player->y][game->player->x + 1] = 'P';
	game->map->map[game->player->y][game->player->x] = tmp;
	game->player->x++;
}

void	right(t_game *game)
{
	if (game->paused
		|| !game->player
		|| !game->map->map[game->player->y][game->player->x + 1]
		|| game->map->map[game->player->y][game->player->x + 1] == '1')
		return ;
	game->player->moves++;
	game->player->direction = 'R';
	move(game);
}
