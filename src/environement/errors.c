/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:28:19 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 08:53:12 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check(t_game *game)
// {
// 	// check_map(game);
// 	// check_player(game);
// 	// check_collectibles(game);
// 	// check_exits(game);
// }

void	error(char *msg, t_game *game)
{
	ft_printf("Error: %s\n", msg);
	if (game)
		close_window(game);
	exit(EXIT_FAILURE);
}
