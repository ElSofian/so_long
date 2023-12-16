/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:13 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/16 13:43:26 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("An error occured while initializing mlx", game);
	game->window = mlx_new_window(game->mlx, game->map->width,
			game->map->height, "So_long");
	if (!game->window)
		error("An error occured while creating window\n", game);
}