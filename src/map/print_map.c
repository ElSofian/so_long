/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:27:31 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 14:19:11 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->map->img.addr + (y * game->map->img.line_length
			+ x * (game->map->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_elements(t_game *game, int x, int y, int i, int j)
{
	if (game->map->map[y][x] == '1')
		print_pixel(game, x * 64 + j, y * 64 + i, 0x000000);
	else if (game->map->map[y][x] == '0')
		print_pixel(game, x * 64 + j, y * 64 + i, 0xFFFFFF);
	else if (game->map->map[y][x] == 'P')
		print_pixel(game, x * 64 + j, y * 64 + i, 0x00FF00);
	else if (game->map->map[y][x] == 'C')
		print_pixel(game, x * 64 + j, y * 64 + i, 0x0000FF);
	else if (game->map->map[y][x] == 'E')
		print_pixel(game, x * 64 + j, y * 64 + i, 0xFF0000);
	if (game->player->x == x && game->player->y == y)
		print_pixel(game, x * 64 + j, y * 64 + i, 0xFFFF00);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width / game->map->height)
		{
			i = -1;
			while (++i < 64)
			{
				j = -1;
				while (++j < 64)
					print_elements(game, x, y, i, j);
			}
		}
	}
}
