/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:19 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 12:55:43 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_player *player)
{
	if (!player)
		return ;
	player->y--;
	player->moves++;
	ft_printf("Moves: %d (Player moved up)\n", player->moves);
}
