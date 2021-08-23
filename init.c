/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:04:06 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/22 18:34:30 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->linelength = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	img->path = NULL;
}

static void	ft_init_ptrs(t_game *game)
{
	game->ptrs->mlx = NULL;
	game->ptrs->win = NULL;
}


t_game	*ft_init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map2d = NULL;
	game->player = (t_player *)malloc(sizeof(t_player));
	game->img = (t_img *)malloc(sizeof(t_img));
	ft_init_img(game->img);
	game->ptrs = (t_ptrs *)malloc(sizeof(t_ptrs));
	ft_init_ptrs(game);
	game->so_wall = (t_img *)malloc(sizeof(t_img));
	game->no_wall = (t_img *)malloc(sizeof(t_img));
	game->we_wall = (t_img *)malloc(sizeof(t_img));
	game->ea_wall = (t_img *)malloc(sizeof(t_img));
	game->floor = 0;
	game->ceil = 0;
	if (!game || !game->img || !game->ptrs || !game->no_wall
		|| !game->so_wall || !game->ea_wall || !game->we_wall || !game->player)
		ft_free_exit(game);
	return (game);
}
