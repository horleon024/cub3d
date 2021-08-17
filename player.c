/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:13:20 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/13 14:19:06 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_get_player_position(t_game *game)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (game->map2d[i])
	{
		j = 0;
		while (game->map2d[i][j])
		{
			if (game->map2d[i][j] == 'N' || (game->map2d[i][j] == 'E'
			|| (game->map2d[i][j] == 'S' || (game->map2d[i][j] == 'W')
			{
				game->player->pos_y = j;
				game->player->pos_x = i;
				game->player->direction = game->map2d[i][j];
				nb++;
			}
			j++;
		}
		i++;
	}
	return (nb == 1);
}
