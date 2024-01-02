/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:41:23 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 14:24:38 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_trajectory(t_game *game, t_ghost *ghost)
{
	if (ghost->direction == 'R'
		&& (ghost->moves == 3 || game->map->map[ghost->y][ghost->x + 1] == '1'))
	{
		ghost->moves = 0;
		ghost->direction = 'L';
	}
	else if (ghost->direction == 'L'
		&& (ghost->moves == 3 || game->map->map[ghost->y][ghost->x - 1] == '1'))
	{
		ghost->moves = 0;
		ghost->direction = 'R';
	}
}

static int	move_ghost(t_game *game, t_ghost *ghost)
{
	char	tmp;

	if (ghost->direction == 'L')
	{
		tmp = game->map->map[ghost->y][ghost->x - 1];
		if (tmp == 'P')
			return (send_message(game, false), close_window(game), 0);
		game->map->map[ghost->y][ghost->x - 1] = 'G';
		game->map->map[ghost->y][ghost->x] = tmp;
		ghost->x--;
	}
	else if (ghost->direction == 'R')
	{
		tmp = game->map->map[ghost->y][ghost->x + 1];
		if (tmp == 'P')
			return (send_message(game, false), close_window(game), 0);
		game->map->map[ghost->y][ghost->x + 1] = 'G';
		game->map->map[ghost->y][ghost->x] = tmp;
		ghost->x++;
	}
	return (1);
}

int	ghosts(t_game *game)
{
	t_ghost			*tmp;
	clock_t			current_time;
	static clock_t	last_time = 0;

	current_time = clock();
	if ((double)(current_time - last_time) / CLOCKS_PER_SEC < 1.0)
		return (0);
	tmp = game->ghost;
	while (tmp)
	{
		check_trajectory(game, tmp);
		move_ghost(game, tmp);
		tmp->moves++;
		tmp = tmp->next;
	}
	render_map(game);
	last_time = current_time;
	return (0);
}
