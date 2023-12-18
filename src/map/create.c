/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:46:41 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 12:21:49 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_map(char *msg, t_game *game)
{
	ft_printf("Error: %s\n", msg);
	if (game)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game->map->path);
		free(game->map->name);
		free(game->map);
		free(game);
	}
	exit(EXIT_FAILURE);
}

static int	open_file(t_game *game)
{
	int		fd;
	int		ret;

	if (!game->map->path)
		error_map("Map file path is NULL in open_file() function.", game);
	fd = open(game->map->path, O_RDONLY);
	ret = access(game->map->path, R_OK);
	if (fd < 0 || ret < 0)
	{
		close(fd);
		error_map("Map file not found, or not readable.", game);
	}
	return (fd);
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
