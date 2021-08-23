/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:04:22 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/22 18:37:17 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_printerror(char *msg, t_game *game)
{
	printf("Error\n");
	printf("%s\n", msg);
	ft_free_exit(game);
	exit(EXIT_FAILURE);
}

static bool	ft_line_is_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (false);
	i = ft_strlen(line) - 1;
	while (line[i] == ' ')
		i--;
	if (line[i] != '1')
		return (false);
	return (true);
}

bool	ft_map_is_valid(char **map, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		if (i == lines || i == 0)
		{
			while (map[i][j])
			{
				if (map[i][j] != ' ' && map[i][j] != '1')
					return (false);
				j++;
			}
		}
		else if (!ft_line_is_valid(map[i]))
			return (false);
		i++;
	}
	return (true);
}
