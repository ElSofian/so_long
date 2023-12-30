/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ghost_anims.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:28:35 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 08:06:12 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_ghost_anims(t_game *game)
{
	int	size;

	size = SIZE;
	game->map->img.ghost = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Ghosts/B/ghost_right1.xpm",
			&size, &size);
	game->map->img.ghost_up = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Ghosts/B/ghost_up1.xpm",
			&size, &size);
	game->map->img.ghost_down = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Ghosts/B/ghost_down1.xpm",
			&size, &size);
	game->map->img.ghost_right = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Ghosts/B/ghost_right1.xpm",
			&size, &size);
	game->map->img.ghost_left = mlx_xpm_file_to_image(game->mlx,
			"./assets/sprites/Ghosts/B/ghost_left1.xpm",
			&size, &size);
}
