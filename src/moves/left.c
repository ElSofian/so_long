/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/18 12:56:01 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_player *player)
{
	if (!player)
		return ;
	player->x--;
	player->moves++;
	ft_printf("Moves: %d (Player moved left)\n", player->moves);
}
