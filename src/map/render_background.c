/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:22:19 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 14:24:28 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				print_image(game, game->map->img.wall, x * 32, y * 32);
			else if (game->map->map[y][x] == '0')
				print_image(game, game->map->img.floor, x * 32, y * 32);
			else if (game->map->map[y][x] == 'C')
				print_image(game, game->map->img.collect, x * 32, y * 32);
			else if (game->map->map[y][x] == 'E')
				print_image(game, game->map->img.exit, x * 32, y * 32);
			else if (game->map->map[y][x] == 'P')
				print_image(game, game->map->img.player, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
}