/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 08:38:55 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game)
{
	char	tmp;

	if (game->map->map[game->player->y][game->player->x - 1] == 'E'
		&& game->player->collectibles == game->map->collectibles)
	{
		game->player->moves++;
		ft_printf("You won in %d moves !\n", game->player->moves);
		close_window(game);
	}
	if (game->map->map[game->player->y][game->player->x - 1] == 'C')
	{
		tmp = '0';
		game->player->collectibles++;
	}
	else
		tmp = game->map->map[game->player->y][game->player->x - 1];
	game->map->map[game->player->y][game->player->x - 1] = 'P';
	game->map->map[game->player->y][game->player->x] = tmp;
	game->player->x--;
	mlx_put_image_to_window(game->mlx, game->window, game->map->img.img, 0, 0);
}

void	left(t_game *game)
{
	if (!game->player
		|| !game->map->map[game->player->y][game->player->x - 1]
		|| game->map->map[game->player->y][game->player->x - 1] == '1')
		return ;
	game->player->moves++;
	game->player->direction = 'L';
	move(game);
}
