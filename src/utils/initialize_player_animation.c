/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player_animation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:57:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/19 10:00:18 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_player_animation(t_game *game, int size)
{
	game->map->img.player_up = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Pac-Man/pac_open_up.xpm",
			&size, &size);
	game->map->img.player_down = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Pac-Man/pac_open_down.xpm",
			&size, &size);
	game->map->img.player_right = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Pac-Man/pac_open_right.xpm",
			&size, &size);
	game->map->img.player_left = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Pac-Man/pac_open_left.xpm",
			&size, &size);
}
