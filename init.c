/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:04:06 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/13 15:11:28 by lhorefto         ###   ########.fr       */
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

static void	ft_init_player(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	ft_init_ray(t_ray *ray)
{
	ray->hit = 0;
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map2d = NULL;
	game->player = (t_player *)malloc(sizeof(t_player));
	ft_init_player(game->player);
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	ft_init_ray(game->ray);
	game->time = 0;
	game->old_time = 0;
	game->img = (t_img *)malloc(sizeof(t_img));
	ft_init_img(game->img);
	game->ptrs = (t_ptrs *)malloc(sizeof(t_ptrs));
	ft_init_ptrs(game);
	game->so_wall = (t_img *)malloc(sizeof(t_img));
	game->no_wall = (t_img *)malloc(sizeof(t_img));
	game->we_wall = (t_img *)malloc(sizeof(t_img));
	game->ea_wall = (t_img *)malloc(sizeof(t_img));
	game->floor = NULL;
	game->ceil = NULL;
	if (!game || !game->img || !game->ptrs || !game->no_wall || !game->ray
		|| !game->so_wall || !game->ea_wall || !game->we_wall || !game->player)
		ft_free_exit(game);
	return (game);
}
