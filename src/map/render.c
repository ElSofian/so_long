/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:57:02 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 11:18:27 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

void	render_player(t_game *game, int x, int y)
{
	int	size;

	size = SIZE;
	if (game->player->direction == 'N')
		render_image(game, game->map->img.player, x, y);
	else if (game->player->direction == 'R')
		render_image(game, game->map->img.player_right, x, y);
	else if (game->player->direction == 'L')
		render_image(game, game->map->img.player_left, x, y);
	else if (game->player->direction == 'U')
		render_image(game, game->map->img.player_up, x, y);
	else if (game->player->direction == 'D')
		render_image(game, game->map->img.player_down, x, y);
}

int	render_elements(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'H')
		render_image(game, game->map->img.floor, x * SIZE, y * SIZE);
	if (game->map->map[y][x] == '1')
		render_image(game, game->map->img.wall, x * SIZE, y * SIZE);
	if (game->map->map[y][x] == 'E'
		&& game->player->collectibles == game->map->collectibles)
		render_image(game, game->map->img.exit, x * SIZE, y * SIZE);
	if (game->map->map[y][x] == 'C')
		render_image(game, game->map->img.collectible, x * SIZE, y * SIZE);
	if (game->map->map[y][x] == 'P')
		render_player(game, x * SIZE, y * SIZE);
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
		while (x < (game->map->width / game->map->height))
		{
			render_elements(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
