/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:50:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 11:31:26 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	manage_keys(int key, t_game *game)
{
	if (key == ESCAPE)
		close_window(game);
	else if (key == UP || key == W)
		up(game->player);
	else if (key == DOWN || key == S)
		down(game->player);
	else if (key == LEFT || key == A)
		left(game->player);
	else if (key == RIGHT || key == D)
		right(game->player);
	return (0);
}
