/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:57:02 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 08:24:29 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_game *game, int x, int y)
{
	if (game->player->direction == 'R')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->img.player_right, x, y);
	else if (game->player->direction == 'L')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->img.player_left, x, y);
	else if (game->player->direction == 'U')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->img.player_up, x, y);
	else if (game->player->direction == 'D')
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->img.player_down, x, y);
}

int	render_elements(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < (game->map->width / game->map->height))
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->map->img.wall, x * SIZE, y * SIZE);
			if (game->map->map[y][x] == 'E'
				&& game->player->collectibles == game->map->collectibles)
				mlx_put_image_to_window(game->mlx, game->window,
					game->map->img.exit, x * SIZE, y * SIZE);
			if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->map->img.collectible, x * SIZE, y * SIZE);
			if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->map->img.player_right, x * SIZE, y * SIZE);
		}
	}
	return (0);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_elements(game);
			x++;
		}
		y++;
	}
	return (0);
}
