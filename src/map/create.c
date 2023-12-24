/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:46:41 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 11:21:07 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_collectible_pos(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	game->map->collectibles_pos = (int **)malloc(sizeof(int *)
			* ft_occ_tab(game->map->map, 'C'));
	if (!game->map->collectibles_pos)
		error("An error occured while creating map. (5)", game);
	while (y-- > 0)
	{
		x = game->map->width / game->map->height;
		while (x-- > 0)
		{
			if (game->map->map[y][x] == 'C')
			{
				game->map->collectibles_pos[i] = (int *)malloc(sizeof(int) * 3);
				if (!game->map->collectibles_pos[i])
					error("An error occured while creating map. (6)", game);
				game->map->collectibles_pos[i][0] = x;
				game->map->collectibles_pos[i][1] = y;
				i++;
			}
		}
	}
}

static void	set_pos(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < (game->map->width / game->map->height))
		{
			if (game->map->map[y][x] == 'P')
			{
				game->map->player_pos[0] = x;
				game->map->player_pos[1] = y;
			}
			else if (game->map->map[y][x] == 'E')
			{
				game->map->map[y][x] = '0';
				game->map->exit_pos[0] = x;
				game->map->exit_pos[1] = y;
			}
		}
	}
	add_collectible_pos(game, x, y);
}

static void	set_map(t_game *game, char *res, int height)
{
	int	row;

	row = ft_strlen(res) / height;
	game->map->map = split(res, row, height);
	if (!game->map->map)
		error("An error occured while creating map. (4)", game);
	game->map->width = ft_strlen(res);
	game->map->height = height;
	game->map->collectibles = ft_occ_tab(game->map->map, 'C');
	set_pos(game);
	free(res);
}

static char	*append(t_game *game, char *res, char *line)
{
	char	*new_res;
	char	*trimed_line;

	trimed_line = ft_strtrim(line, " \t\r\n");
	if (!trimed_line)
	{
		free(res);
		free(line);
		error_map("An error occured while creating map. (3)", game);
	}
	new_res = ft_strjoin(res, trimed_line);
	if (!new_res)
	{
		free(res);
		free(line);
		free(trimed_line);
		error_map("An error occured while creating map. (2)", game);
	}
	free(res);
	free(line);
	free(trimed_line);
	return (new_res);
}

int	create_map(t_game *game)
{
	int		fd;
	int		width;
	int		height;
	char	*res;
	char	*line;

	fd = open_file(game);
	res = ft_strdup("");
	if (!res)
		error_map("An error occured while creating map. (1)", game);
	height = 0;
	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line && height == 0 && width == 0)
			error_map("Map file is empty.", game);
		if (!line)
			break ;
		width += ft_strlen(line);
		height++;
		res = append(game, res, line);
	}
	return (close(fd), set_map(game, res, height), 0);
}
