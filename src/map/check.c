/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:50:04 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/17 20:43:17 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(t_game *game, char c)
{
	if (c != 'P' && c != 'C' &&  c != 'E' && c != '1' && c != '0' && c != 13)
		error("Map contains non authorized characters/digits.", game);
}

static void	check_wall(t_game *game, char c, int i, int j)
{
	if (i == 0 && c != '1' && c != 13)
		error("Top wall of the map contains a hole.", game);
	else if (i == game->map->height - 1 && c != '1' && c != 13)
		error("Bottom wall of the map contains a hole.", game);
	else if (j == 0 && c != '1' && c != 13)
		error("Left wall of the map contains a hole.", game);
	else if (j == game->map->width - 1 && c != '1' && c != 13)
		error("Right wall of the map contains a hole.", game);
}

static void	check_over_and_missing(t_game *game, char **map)
{
	int	p_count;
	int	c_count;
	int	e_count;

	p_count = ft_occ_tab(map, 'P');
	c_count = ft_occ_tab(map, 'C');
	e_count = ft_occ_tab(map, 'E');
	if (p_count != 1)
		error("Map doesn't contains or contains too much player spawn.", game);
	else if (c_count != 1)
		error("Map doesn't contains or contains too much collectible.", game);
	else if (e_count != 1)
		error("Map doesn't contains or contains too much no exit.", game);
}

static void	check_rows(t_game *game, char **map)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (ft_strcmp(map[i], "") == 0)
			error("Map contains empty lines.", game);
		j = 0;
		while (map[i][j])
		{
			check_wall(game, map[i][j], i, j);
			check_char(game, map[i][j]);
			j++;
			count++;
		}
		i++;
	}
	// ft_printf("count: %d, width: %d\n", count - 1, game->map->width);
	if (count - 1 != game->map->width)
		error("Map is not a rectangle.", game);
	check_over_and_missing(game, map);
}

void	check(t_game *game)
{
	if (game->map->height == game->map->width)
		error("Map is not a rectangle.", game);
	check_rows(game, game->map->map);
}
