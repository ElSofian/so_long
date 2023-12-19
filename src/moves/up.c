/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:19 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/19 12:53:37 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *game)
{
	char	tmp;

	if (!game->player
		|| !game->map->map[game->player->y - 1][game->player->x]
		|| game->map->map[game->player->y - 1][game->player->x] == '1')
		return ;
	game->player->y--;
	game->player->moves++;
	game->player->direction = 'U';
	tmp = game->map->map[game->player->y][game->player->x];
	game->map->map[game->player->y][game->player->x] = 'P';
	game->map->map[game->player->y + 1][game->player->x] = tmp;
	ft_printf("Moves: %d (Player moved up)   |   Pos : %d / %d\n", game->player->moves, game->player->x, game->player->y);
}
