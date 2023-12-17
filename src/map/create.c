/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:46:41 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/17 17:46:22 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_file(t_game *game)
{
	int		fd;
	int		ret;

	if (!game->map->path)
		error("Game map file path is NULL in open_file() function.", game);
	fd = open(game->map->path, O_RDONLY);
	ret = access(game->map->path, R_OK);
	if (fd < 0 || ret < 0)
	{
		close(fd);
		error("Map file not found, or not readable.", game);
	}
	return (fd);
}

static int	set_map(t_game *game, char *res, int height, int width)
{
	game->map->map = ft_split(res, '\n');
	if (!game->map->map)
		error("An error occured while creating map. (3)", game);
	game->map->height = height * 100;
	game->map->width = (width / (height - 1)) * 100;
	free(res);
	return (0);
}

static char	*append(t_game *game, char *res, char *line)
{
	char *new_res;
	
	new_res = ft_strjoin(res, line);
	if (!new_res)
	{
		free(res);
		free(line);
		error("An error occured while creating map. (1)", game);
	}
	free(res);
	return (new_res);
}

int	create_map(t_game *game)
{
	int		fd;
	int		width;
	int		height;
	char	*res;
	char	*line;
	char	*tmp;

	fd = open_file(game);
	res = ft_strdup("");
	if (!res)
		error("An error occured while creating map. (1)", game);
	height = 0;
	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		width += ft_strlen(line);
		height++;
		res = append(game, res, line);
		free(line);
	}
	return (close(fd),
		set_map(game, res, height, width), 0);
}
