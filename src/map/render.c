/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:57:02 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 14:26:17 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_moves(t_game *game)
{
	char	*moves;
	char	*render;

	moves = ft_itoa(game->player->moves);
	if (!moves)
		error("An error occured while rendering the moves.", game);
	render = ft_strjoin("Movements : ", moves);
	if (!render)
	{
		free(moves);
		error("An error occured while rendering the moves. (2)", game);
	}
	mlx_string_put(game->mlx, game->window, 10, 20, 16777215, render);
	free(moves);
	free(render);
}

void	render_ghost(t_game *game, int x, int y)
{
	int	size;

	size = SIZE;
	if (game->ghost->direction == 'N')
		render_image(game, game->map->img.ghost, x, y);
	else if (game->ghost->direction == 'R')
		render_image(game, game->map->img.ghost_right, x, y);
	else if (game->ghost->direction == 'L')
		render_image(game, game->map->img.ghost_left, x, y);
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
	int	i;

	i = 0;
	if (game->map->map[y][x] == '0')
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
	if (game->map->map[y][x] == 'G')
		render_ghost(game, x * SIZE, y * SIZE);
	return (0);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (game->paused)
		return (0);
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
	render_moves(game);
	return (0);
}
