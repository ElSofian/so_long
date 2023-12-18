/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:13 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 12:59:16 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map->img.img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->player->name);
	free(game->player);
	free(game->map->path);
	free(game->map->name);
	ft_freetab(game->map->map);
	free(game->map);
	free(game);
	exit(EXIT_SUCCESS);
}

void	open_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx,
			(game->map->width / game->map->height) * 64,
			game->map->height * 64, game->map->name);
	if (!game->window)
		error("An error occured while creating window\n", game);
}
