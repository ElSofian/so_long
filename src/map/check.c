/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:50:04 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 11:22:33 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(t_game *game, char c)
{
	if (c != 'P' && c != 'C' && c != 'E' && c != '1' && c != '0' && c != 13)
		error_map("Map contains non authorized characters/digits.", game);
}

static void	check_wall(t_game *game, char c, int i, int j)
{
	if (i == 0 && c != '1' && c != 13)
		error_map("Top wall of the map contains a hole.", game);
	else if (i == game->map->height - 1 && c != '1' && c != 13)
		error_map("Bottom wall of the map contains a hole.", game);
	else if (j == 0 && c != '1' && c != 13)
		error_map("Left wall of the map contains a hole.", game);
	else if (j == game->map->width - 1 && c != '1' && c != 13)
		error_map("Right wall of the map contains a hole.", game);
}

static void	check_over_and_missing(t_game *game)
{
	if (ft_occ_tab(game->map->map, 'P') != 1)
		error_map("Map doesn't contains or too much player spawn.", game);
	else if (ft_occ_tab(game->map->map, 'C') < 1)
		error_map("Map doesn't contains collectible.", game);
	else if (!game->map->exit_pos[0] || !game->map->exit_pos[1])
		error_map("Map doesn't contains or contains too much no exit.", game);
	else if (ft_occ_tab(game->map->map, '0') < 1)
		error_map("Map doesn't contains empty space.", game);
}

void	check(t_game *game)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (game->map->map[i])
	{
		if (ft_strcmp(game->map->map[i], "") == 0)
			error_map("Map contains empty lines.", game);
		j = 0;
		while (game->map->map[i][j])
		{
			check_wall(game, game->map->map[i][j], i, j);
			check_char(game, game->map->map[i][j]);
			j++;
			count++;
		}
		i++;
	}
	if (count != game->map->width)
		error_map("Map is not a rectangle.", game);
	check_over_and_missing(game);
}
