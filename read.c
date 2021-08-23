/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:04:26 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/22 18:59:53 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_get_path(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (ft_strdup(line + i));
}

bool	ft_get_paths(char *path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strncmp(line, "NO ", 3))
			game->no_wall->path = ft_get_path(line + 2);
		else if (!ft_strncmp(line, "SO ", 3))
			game->so_wall->path = ft_get_path(line + 2);
		else if (!ft_strncmp(line, "WE ", 3))
			game->we_wall->path = ft_get_path(line + 2);
		else if (!ft_strncmp(line, "EA ", 3))
			game->ea_wall->path = ft_get_path(line + 2);
		else if (!ft_strncmp(line, "F ", 2))
			game->floor = ft_convert_rgb(line + 1);
		else if (!ft_strncmp(line, "C ", 2))
			game->ceil = ft_convert_rgb(line + 1);
		free(line);
	}
	free(line);
	close(fd);
	return (!game->floor || !game->ceil || !game->ea_wall->path
		|| !game->we_wall->path || !game->no_wall->path
		|| !game->so_wall->path);
}

static bool	ft_valid_map_line(char *line)
{
	int	i;
	int	wall;

	i = 0;
	wall = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'N' && line[i] != 'E')
			return (false);
		if (line[i] == '1' || line[i] == '0')
			wall++;
		i++;
	}
	return (wall >= 2);
}

void	ft_get_map_data(char *path, t_game *game)
{
	int		tmp;
	int		fd;
	char	*line;

	game->grid_h = 0;
	game->grid_w = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_valid_map_line(line))
		{
			tmp = ft_strlen(line);
			if (tmp > game->grid_w)
				game->grid_w = tmp;
			game->grid_h++;
		}
		free(line);
	}
	free(line);
	close(fd);
}

bool	ft_get_2dmap(char *path, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_valid_map_line(line))
		{
			game->map2d[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	game->map2d[i] = ft_strdup(line);
	game->map2d[i + 1] = 0;
	close(fd);
	free(line);
	return (ft_map_is_valid(game->map2d, game->grid_h));
}
