/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:43:52 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/19 12:55:18 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down(t_game *game)
{
	char	tmp;

	if (!game->player
		|| !game->map->map[game->player->y + 1][game->player->x]
		|| game->map->map[game->player->y + 1][game->player->x] == '1')
		return ;
	game->player->y++;
	game->player->moves++;
	game->player->direction = 'D';
	tmp = game->map->map[game->player->y][game->player->x];
	game->map->map[game->player->y][game->player->x] = 'P';
	game->map->map[game->player->y - 1][game->player->x] = tmp;
	ft_printf("Moves: %d (Player moved down)\n   |   Pos : %d / %d\n", game->player->moves, game->player->x, game->player->y);
}
