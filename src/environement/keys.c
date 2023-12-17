/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:50:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/17 17:06:39 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_hooks(t_game *game)
{
	mlx_key_hook(game->window, manage_keys, game);
}

int	manage_keys(int key, t_game *game)
{
	if (key == ESCAPE)
		close_window(game);
	else if (key == UP)
		up(game->player);
	else if (key == DOWN)
		down(game->player);
	else if (key == LEFT)
		left(game->player);
	else if (key == RIGHT)
		right(game->player);
	return (0);
}
