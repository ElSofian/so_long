/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:03 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/17 17:07:12 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_player *player)
{
	if (!player)
		return ;
	player->x -= 10;
	player->moves++;
	ft_printf("Player moved left\n");
}
