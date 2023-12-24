/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:13 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 09:40:01 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map->img.wall);
	mlx_destroy_image(game->mlx, game->map->img.floor);
	mlx_destroy_image(game->mlx, game->map->img.collectible);
	mlx_destroy_image(game->mlx, game->map->img.exit);
	mlx_destroy_image(game->mlx, game->map->img.player_up);
	mlx_destroy_image(game->mlx, game->map->img.player_down);
	mlx_destroy_image(game->mlx, game->map->img.player_right);
	mlx_destroy_image(game->mlx, game->map->img.player_left);
	mlx_destroy_image(game->mlx, game->map->img.img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->player->name);
	free(game->player);
	free(game->map->path);
	free(game->map->name);
	free_int_tab(game, game->map->collectibles_pos);
	ft_freetab(game->map->map);
	free(game->map);
	free(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	open_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx,
			(game->map->width / game->map->height) * SIZE,
			game->map->height * SIZE, game->map->name);
	if (!game->window)
		error("An error occured while creating window\n", game);
}
