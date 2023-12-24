/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:43:52 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 11:25:35 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game)
{
	char	tmp;

	if (game->map->map[game->player->y + 1][game->player->x] == 'E'
		&& game->player->collectibles == game->map->collectibles)
	{
		game->player->moves++;
		ft_printf("You won in %d moves !\n", game->player->moves);
		close_window(game);
	}
	if (game->map->map[game->player->y + 1][game->player->x] == 'C')
	{
		tmp = '0';
		game->player->collectibles++;
		if (game->player->collectibles == game->map->collectibles)
			game->map->map[game->map->exit_pos[1]][game->map->exit_pos[0]]
				= 'E';
	}
	else
		tmp = game->map->map[game->player->y + 1][game->player->x];
	game->map->map[game->player->y + 1][game->player->x] = 'P';
	game->map->map[game->player->y][game->player->x] = tmp;
	game->player->y++;
}

void	down(t_game *game)
{
	if (!game->player
		|| !game->map->map[game->player->y + 1][game->player->x]
		|| game->map->map[game->player->y + 1][game->player->x] == '1')
		return ;
	game->player->moves++;
	game->player->direction = 'D';
	move(game);
}
