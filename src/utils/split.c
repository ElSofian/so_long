/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:11:28 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/19 09:28:49 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*return_error(int err, char **tab)
{
	if (err == 1)
		ft_printf("An error occured while with allocating memory, ft_split.\n");
	else if (err == 2)
		ft_printf("An error has occured while allocate a tab in put_word().\n");
	if (tab)
		ft_freetab(tab);
	return (NULL);
}

char	**split(char *s, int width, int height)
{
	int		i;
	int		j;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (height + 1));
	if (!tab)
		return (return_error(1, NULL));
	i = 0;
	while (i < height)
	{
		tab[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!tab[i])
			return (return_error(2, tab));
		j = 0;
		while (j < width && *s)
		{
			tab[i][j] = *s;
			s++;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
