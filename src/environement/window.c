/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:13 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 08:17:05 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_ghosts(game);
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
