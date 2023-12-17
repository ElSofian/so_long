/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:27:31 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/17 17:06:44 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_image(t_game *game)
{
	game->map->img.img = mlx_new_image(game->mlx, game->map->width * 10,
			game->map->height * 10);
	game->map->img.addr = mlx_get_data_addr(game->map->img.img,
			&game->map->img.bits_per_pixel,
			&game->map->img.line_length, &game->map->img.endian);
}
