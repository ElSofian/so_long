/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:40:57 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/30 12:42:17 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	send_message(t_game *game, bool success)
{
	if (success)
		ft_printf("Congrats %s! You won in %d moves !\n",
			game->player->name, game->player->moves);
	else
		ft_printf("You have been killed by a ghost (with %d moves) !\n",
			game->player->moves);
}
