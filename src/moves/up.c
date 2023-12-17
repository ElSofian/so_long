/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:44:19 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/17 17:07:10 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_player *player)
{
	if (!player)
		return ;
	player->y -= 10;
	player->moves++;
	ft_printf("Player moved up\n");
}
