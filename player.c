/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:13:20 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/22 19:12:44 by lhorefto         ###   ########.fr       */
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
			if (game->map2d[i][j] == 'N' || game->map2d[i][j] == 'E'
			|| game->map2d[i][j] == 'S' || game->map2d[i][j] == 'W')
			{
				game->player->startx = j;
				game->player->starty = i;
				game->player->start_dir = game->map2d[i][j];
				nb++;
			}
			j++;
		}
		i++;
	}
	return (nb == 1);
}
