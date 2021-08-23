/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:04:19 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/22 19:00:58 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_map2d(t_game *game)
{
	int	i;

	i = game->grid_h;
	if (i < 0)
		return ;
	while (i >= 0)
	{
		if (game->map2d[i])
			free(game->map2d[i]);
		i--;
	}
	free(game->map2d);
}

void	ft_free_exit(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	if (game->ptrs)
		free(game->ptrs);
	if (game->so_wall)
		free(game->so_wall);
	if (game->no_wall)
		free(game->no_wall);
	if (game->we_wall)
		free(game->we_wall);
	if (game->ea_wall)
		free(game->ea_wall);
	if (game->img)
		free(game->img);
	if (game->map2d)
		ft_free_map2d(game);
	if (game->player)
		free(game->player);
	if (game)
		free(game);
	exit(EXIT_SUCCESS);
}

int	ft_close_clean(t_game *game)
{
	if (game->img->img_ptr)
		mlx_destroy_image(game->ptrs->mlx, game->img->img_ptr);
	if (game->ptrs->win)
		mlx_destroy_window(game->ptrs->mlx, game->ptrs->win);
	if (game->ptrs->mlx)
		mlx_destroy_display(game->ptrs->mlx);
	if (game->ptrs->mlx)
		free(game->ptrs->mlx);
	ft_free_exit(game);
	exit(EXIT_SUCCESS);
	return (1);
}
