/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:04:11 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/13 14:20:05 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_init_game();
	if (argc != 2)
		ft_printerror("Wrong number of arguments!", game);
	if (ft_get_paths(argv[1], game))
		ft_printerror("Missing path for one of textures!", game);
	ft_get_map_data(argv[1], game);
	game->map2d = (char **)malloc(sizeof(char *) * (game->map_lines + 1));
	if (!game->map2d)
		ft_free_exit(game);
	if (!ft_get_2dmap(argv[1], game))
		ft_printerror("Map is not surrounded by walls!", game);
	if (!ft_get_player_position(game))
		ft_printerror("Wrong number of player starting positions!", game);
	ft_start_game(game);
	return (0);
}
