/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/19 12:53:29 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_game *game)
{
	char	tmp;

	if (!game->player
		|| !game->map->map[game->player->y][game->player->x - 1]
		|| game->map->map[game->player->y][game->player->x - 1] == '1')
		return ;
	game->player->x--;
	game->player->moves++;
	game->player->direction = 'L';
	tmp = game->map->map[game->player->y][game->player->x];
	game->map->map[game->player->y][game->player->x] = 'P';
	game->map->map[game->player->y][game->player->x + 1] = tmp;
	ft_printf("Moves: %d (Player moved left)   |   Pos : %d / %d\n", game->player->moves, game->player->x, game->player->y);
}
