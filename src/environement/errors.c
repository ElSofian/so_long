/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:28:19 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 13:53:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *msg, t_game *game)
{
	ft_printf("Error: %s\n", msg);
	if (game)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game->map->path);
		free(game->map->name);
		free_int_tab(game, game->map->collectibles_pos);
		ft_freetab(game->map->map);
		free(game->map);
		free(game);
	}
	exit(EXIT_FAILURE);
}

void	error(char *msg, t_game *game)
{
	ft_printf("Error: %s\n", msg);
	if (game)
		close_window(game);
	exit(EXIT_FAILURE);
}
