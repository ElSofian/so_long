/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:45:17 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 10:27:12 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map->img.wall);
	mlx_destroy_image(game->mlx, game->map->img.floor);
	mlx_destroy_image(game->mlx, game->map->img.collectible);
	mlx_destroy_image(game->mlx, game->map->img.exit);
	mlx_destroy_image(game->mlx, game->map->img.player_right);
	mlx_destroy_image(game->mlx, game->map->img.player_left);
	mlx_destroy_image(game->mlx, game->map->img.player_up);
	mlx_destroy_image(game->mlx, game->map->img.player_down);
	mlx_destroy_image(game->mlx, game->map->img.img);
	free(game->map->img.img);
}