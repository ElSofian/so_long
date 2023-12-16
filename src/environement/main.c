/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:07:08 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/16 13:42:09 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	*game;
	
	game = NULL;
	initialize(game);
}

int	test(void)
{
	void	*mlx_connexion;
	void	*mlx_window;

	mlx_connexion = mlx_init();
	if (!mlx_connexion)
	{
		ft_printf("An error occured while initializing mlx\n");
		return (1);
	}
	mlx_window = mlx_new_window(mlx_connexion, 400, 400, "So_long");
	if (!mlx_window)
	{
		ft_printf("An error occured while creating window\n");
		mlx_destroy_display(mlx_connexion);
		free(mlx_connexion);
		return (2);
	}
	mlx_loop(mlx_connexion);
	mlx_destroy_display(mlx_connexion);
	free(mlx_connexion);
	return (0);
}