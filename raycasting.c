/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:22:39 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/13 15:42:56 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda(t_game *game)
{
	while (game->ray->hit == 0)
	{
		if (game->ray->sidedist_x < game->ray->sidedist_y)
		{
			game->ray->sidedist_x += game->ray->deltadist_x;
			game->ray->map_x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->sidedist_y += game->ray->deltadist_y;
			game->ray->map_y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->map2d[game->ray->map_x][game->ray->map_y] == '1')
			game->ray->hit = 1;
	}
}

int	ft_raycasting(t_game *game)
{
	int	i;

	i = 0;
	while (i < SCREENWIDTH)
	{
		game->ray->camera_x = 2 * i / double(SCREENWIDTH) - 1;
		game->ray->raydir_x = game->player->dir_x + game->player->plane_x
			* game->ray->camera_x;
		game->ray->raydir_y = game->player->dir_y + game->player->plane_y
			* game->ray->camera_x;
		game->ray->map_x = (int)game->player->pos_x;
		game->ray->map_x = (int)game->player->pos_y;
		game->ray->deltadist_x = abs(1 / game->ray->raydir_x);
		game->ray->deltadist_y = abs(1 / game->ray->raydir_y);
		if (game->ray->raydir_x < 0)
		{
			game->ray->step_x = -1;
			game->ray->sidedist_x = (game->player->pos_x - game->ray->map_x)
				* game->ray->deltadist_x;
		}
		else
		{
			game->ray->step_x = 1;
			game->ray->sidedist_x = (game->ray->map_x + 1.0 - game->player->pos_x)
				* game->ray->deltadist_x;
		}
		if (game->ray->raydir_y < 0)
		{
			game->ray->step_y = -1;
			game->ray->sidedist_y = (game->player->pos_y - game->ray->map_y)
				* game->ray->deltadist_y;
		}
		else
		{
			game->ray->step_y = 1;
			game->ray->sidedist_y = (game->ray->map_y + 1.0 - game->player->pos_y)
				* game->ray->deltadist_y;
		}
		ft_dda(game);
		if (game->ray->side)
			game->ray->perpwalldist = (game->ray->map_y - game->player->pos_y
				+ (1 - game->ray->step_y) / 2) / game->ray->raydir_y;
		else
			game->ray->perpwalldist = (game->ray->map_x - game->player->pos_x
				+ (1 - game->ray->step_x) / 2) / game->ray->raydir_x;
		i++;
	}
}