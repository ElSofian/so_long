/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ghosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:16:26 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 13:00:45 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ghosts(t_game *game)
{
	t_ghost	*tmp;

	if (!game->ghost)
		return ;
	while (game->ghost)
	{
		tmp = game->ghost;
		game->ghost = game->ghost->next;
		if (tmp)
			free(tmp);
	}
}
