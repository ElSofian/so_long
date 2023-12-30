/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 08:43:57 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/24 09:39:20 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_int_tab(t_game *game, int **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (++i < game->map->collectibles)
		free(tab[i]);
	free(tab);
}
