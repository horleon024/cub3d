/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:55:38 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/13 14:06:37 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_load_image(t_game *game, t_img *img, void *mlx, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img_ptr)
	{
		ft_putstr_fd("Error\nWhile loading images\n", 2);
		ft_free_exit(game);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->linelength, &img->endian);
}

void	ft_start_game(t_game *game)
{
	game->ptrs->mlx = mlx_init();
	game->ptrs->win = mlx_new_window(game->ptrs->mlx, SCREENWIDTH,
		SCREENHEIGHT, "CUB3D");
	game->img->img_ptr = mlx_new_image(game->ptrs->mlx,
			SCREENWIDTH, SCREENHEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->img_ptr,
			&game->img->bits_per_pixel,
			&game->img->linelength, &game->img->endian);
	ft_load_image(game, game->so_wall, game->ptrs->mlx, game->so_wall->path);
	ft_load_image(game, game->no_wall, game->ptrs->mlx, game->no_wall->path);
	ft_load_image(game, game->we_wall, game->ptrs->mlx, game->we_wall->path);
	ft_load_image(game, game->ea_wall, game->ptrs->mlx, game->ea_wall->path);



	mlx_hook(game->ptrs->mlx, 33, 32, ft_close_clean, game);
	mlx_loop(game->ptrs->mlx);
}