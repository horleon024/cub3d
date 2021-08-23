#include "cub3d.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

float	check_limits2(float O)
{
	if (O > M_PI - 0.012 && O < M_PI)
		O = M_PI - 0.012;
	else if (O > M_PI && O < M_PI + 0.012)
		O = M_PI + 0.012;
	if (O > (3 * M_PI / 2) - 0.012 && O < (3 * M_PI / 2))
		O = (3 * M_PI / 2) - 0.012;
	else if (O > (3 * M_PI / 2) && O < (3 * M_PI / 2) + 0.012)
		O = (3 * M_PI / 2) + 0.012;
	return (O);
}

float	check_limits(float O)
{
	if (O < -0.012)
		O += (2 * M_PI);
	else if (O > (2 * M_PI) - 0.012)
		O -= (2 * M_PI);
	else if (O > 0 && O < 0.012)
		O = 0.012;
	else if (O < (2 * M_PI) && O > (2 * M_PI) - 0.012)
		O = (2 * M_PI) - 0.012;
	// if (O > (M_PI / 2) - 0.012 && O < (M_PI / 2))
	// 	O = (M_PI / 2) - 0.012;
	// else if (O > (M_PI / 2) && O < (M_PI / 2) + 0.012)
	// 	O = (M_PI / 2) + 0.012;
	O = check_limits2(O);
	return (O);
}

int	xdist_quad1(float O, t_game *game)
{
	int	x_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x_dist = 20000 * max(game->grid_w, game->grid_h);
	dx = (game->player->posx % 100); //x goes to nearest line on left
	dy = dx * tan(O); //diff in y depends on angle
	x = game->player->posx - dx; //x and y are the positions of the ray when intersecting a vertical line
	y = game->player->posy - dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[((y - 1) / 100)][(x - 1) / 100] == 1) //i-j coordinates of the block that the ray is intersecting (on the grid) :
		{
			x_dist = dx / cos(O); //length of the ray
			break ;
		}
		dx += 100; //if grid value of block is 0 (empty space), keep going to the next vertical line until intersection with grid value 1 found
		dy = dx * tan(O);
		x = game->player->posx - dx;
		y = game->player->posy - dy;
	}
	return (x_dist);
}

int	ydist_quad1(float O, t_game *game)
{
	int	y_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	y_dist = 20000 * max(game->grid_w, game->grid_h);
	dy = game->player->posy % 100;
	dx = dy / tan(O);
	x = game->player->posx - dx;
	y = game->player->posy - dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[(y - 1) / 100][((x - 1) / 100)] == 1)
		{
			y_dist = dy / sin(O);
			break ;
		}
		dy += 100;
		dx = dy / tan(O);
		x = game->player->posx - dx;
		y = game->player->posy - dy;
	}
	return (y_dist);
}

int	xdist_quad2(float O, t_game *game)
{
	int	x_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x_dist = 20000 * max(game->grid_w, game->grid_h);
	dx = 100 - (game->player->posx % 100);
	dy = dx * tan(M_PI - O);
	x = game->player->posx + dx;
	y = game->player->posy - dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[((y - 1) / 100)][(x + 1) / 100] == 1)
		{
			x_dist = dy / sin(M_PI - O);
			break ;
		}
		dx += 100;
		dy = dx * tan(M_PI - O);
		x = game->player->posx + dx;
		y = game->player->posy - dy;
	}
	return (x_dist);
}

int	ydist_quad2(float O, t_game *game)
{
	int	y_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	y_dist = 20000 * max(game->grid_w, game->grid_h);
	dy = game->player->posy % 100;
	dx = dy / tan(M_PI - O);
	x = game->player->posx + dx;
	y = game->player->posy - dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[(y - 1) / 100][x / 100] == 1)
		{
			y_dist = dy / sin(M_PI - O);
			break ;
		}
		dy += 100;
		dx = dy / tan(M_PI - O);
		x = game->player->posx + dx;
		y = game->player->posy - dy;
	}
	return (y_dist);
}

int	xdist_quad3(float O, t_game *game)
{
	int	x_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x_dist = 20000 * max(game->grid_w, game->grid_h);
	dx = 100 - (game->player->posx % 100);
	dy = dx * tan(O - M_PI);
	x = game->player->posx + dx;
	y = game->player->posy + dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[(y / 100)][(x + 1) / 100] == 1)
		{
			x_dist = dx / cos(O - M_PI);
			break ;
		}
		dx += 100;
		dy = dx * tan(O - M_PI);
		x = game->player->posx + dx;
		y = game->player->posy + dy;
	}
	return (x_dist);
}

int	ydist_quad3(float O, t_game *game)
{
	int	y_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	y_dist = 20000 * max(game->grid_w, game->grid_h);
	dy = 100 - (game->player->posy % 100);
	dx = dy / tan(O - M_PI);
	x = game->player->posx + dx;
	y = game->player->posy + dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[(y + 1) / 100][x / 100] == 1)
		{
			y_dist = dy / sin(O - M_PI);
			break ;
		}
		dy += 100;
		dx = dy / tan(O - M_PI);
		x = game->player->posx + dx;
		y = game->player->posy + dy;
	}
	return (y_dist);
}

int	xdist_quad4(float O, t_game *game)
{
	int	x_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x_dist = 20000 * max(game->grid_w, game->grid_h);
	dx = (game->player->posx % 100);
	dy = dx * tan((2 * M_PI) - O);
	x = game->player->posx - dx;
	y = game->player->posy + dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[(y / 100)][(x - 1) / 100] == 1)
		{
			x_dist = dy / sin((2 * M_PI) - O);
			break ;
		}
		dx += 100;
		dy = dx * tan((2 * M_PI) - O);
		x = game->player->posx - dx;
		y = game->player->posy + dy;
	}
	return (x_dist);
}

int	ydist_quad4(float O, t_game *game)
{
	int	y_dist;
	int	dx;
	int	dy;
	int	x;
	int	y;

	y_dist = 20000 * max(game->grid_w, game->grid_h);
	dy = 100 - (game->player->posy % 100);
	dx = dy / tan((2 * M_PI) - O);
	x = game->player->posx - dx;
	y = game->player->posy + dy;
	while (x > 0 && x < (game->grid_w * 100) && y > 0 && y < (game->grid_h * 100))
	{
		if (game->map2d[(y) / 100][(x - 1) / 100] == 1)
		{
			y_dist = dy / sin((2 * M_PI) - O);
			break ;
		}
		dy += 100;
		dx = dy / tan((2 * M_PI) - O);
		x = game->player->posx - dx;
		y = game->player->posy + dy;
	}
	return (y_dist);
}

int	which_wall(int dists_fov[250][2], int i)
{
	int	wall;

	wall = 0x000000;
	if (dists_fov[i / 2][1] == 1)
		wall = WWALL;
	else if (dists_fov[i / 2][1] == 2)
		wall = NWALL;
	else if (dists_fov[i / 2][1] == 3)
		wall = EWALL;
	else if (dists_fov[i / 2][1] == 4)
		wall = SWALL;
	return (wall);
}

void	paint_screen(int dists_fov[250][2], int i, t_game *game)
{
	int	j;
	int	wall;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < (250 - (dists_fov[i / 2][0] / 2)))
		{
			mlx_pixel_put(game->ptrs->mlx, game->ptrs->win, i, j, CEIL);
			j++;
		}
		while (j < (250 + (dists_fov[i / 2][0] / 2)) && j < 500)
		{
			wall = which_wall(dists_fov, i);
			mlx_pixel_put(game->ptrs->mlx, game->ptrs->win, i, j, wall);
			j++;
		}
		while (j < 500)
		{
			mlx_pixel_put(game->ptrs->mlx, game->ptrs->win, i, j, FLOOR);
			j++;
		}
		i++;
	}
}

int	set_dists_wall(int *x_dist, int *y_dist, int wall, float O, t_game *game)
{
	if (O >= 0 && O < M_PI / 2)
	{
		*x_dist = xdist_quad1(O, game);
		*y_dist = ydist_quad1(O, game);
		wall = (*x_dist > *y_dist ? 4 : 3);
	}
	else if (O >= M_PI / 2 && O < M_PI)
	{
		*x_dist = xdist_quad2(O, game);
		*y_dist = ydist_quad2(O, game);
		wall = (*x_dist > *y_dist ? 4 : 1);
	}
	else if (O >= M_PI && O < 3 * M_PI / 2)
	{
		*x_dist = xdist_quad3(O, game);
		*y_dist = ydist_quad3(O, game);
		wall = (*x_dist > *y_dist ? 2 : 1);
	}
	else if (O >= 3 * M_PI / 2 && O < 2 * M_PI)
	{
		*x_dist = xdist_quad4(O, game);
		*y_dist = ydist_quad4(O, game);			
		wall = (*x_dist > *y_dist ? 2 : 3);
	}
	return (wall);
}

int	cast_rays(t_game *game)
{
	int		x_dist;
	int		y_dist;
	int		mindist;
	int		wall; //W=1, N=2, E=3, S=4;
	int		dists_fov[250][2];
	int		i;
//	int		j;
	float	O;

	i = -1;
	O = game->player->O - 0.6;
	while (++i < 250)
	{
		O = check_limits(O);
		wall = set_dists_wall(&x_dist, &y_dist, wall, O, game);
		mindist = min(x_dist, y_dist);
		dists_fov[i][0] = 50000 / (mindist * cos(fabsf(game->player->O - O)));
		dists_fov[i][1] = wall;
		O += 0.0048;
	}
	paint_screen(dists_fov, 0, game);
	return (1);
}

float	angle_change(int dir, float ang)
{
	if (dir == 0)
		ang -= 0.05;
	else if (dir == 1)
		ang += 0.05;
	if (ang < 0)
		ang += (2 * M_PI);
	else if (ang > 2 * M_PI)
		ang -= (2 * M_PI);
	return (ang);
}

void	keys_AW(int key, t_game *game)
{
	if (key == A) //A
	{
		game->player->posx -= 10 * cos(game->player->O - M_PI / 2);
		game->player->posy -= 10 * sin(game->player->O - M_PI / 2);
		if (game->map2d[(game->player->posy / 100)][game->player->posx / 100] == 1)
		{
			game->player->posx += 10 * cos(game->player->O - M_PI / 2);
			game->player->posy += 10 * sin(game->player->O - M_PI / 2);
		}
	}
	if (key == W || key == 126) //W
	{
		game->player->posx -= 10 * cos(game->player->O);
		game->player->posy -= 10 * sin(game->player->O);
		if (game->map2d[(game->player->posy / 100)][game->player->posx / 100] == 1)
		{
			game->player->posx += 10 * cos(game->player->O);
			game->player->posy += 10 * sin(game->player->O);
		}
	}
}

void	keys_DS(int key, t_game *game)
{
	if (key == D) //D
	{
		game->player->posx -= 10 * cos(game->player->O + M_PI / 2);
		game->player->posy -= 10 * sin(game->player->O + M_PI / 2);
		if (game->map2d[(game->player->posy / 100)][game->player->posx / 100] == 1)
		{
			game->player->posx += 10 * cos(game->player->O + M_PI / 2);
			game->player->posy += 10 * sin(game->player->O + M_PI / 2);
		}
	}
	if (key == S || key == 125) //S
	{
		game->player->posx += 10 * cos(game->player->O);
		game->player->posy += 10 * sin(game->player->O);
		if (game->map2d[(game->player->posy / 100)][game->player->posx / 100] == 1)
		{
			game->player->posx -= 10 * cos(game->player->O);
			game->player->posy -= 10 * sin(game->player->O);
		}
	}
}

int	deal_key(int key, t_game *game)
{
	printf("Key: %d\n", key);
	if (key == 65307)
		exit(0);
	keys_AW(key, game);
	keys_DS(key, game);
	if (key == 65361)
		game->player->O = angle_change(0, game->player->O);
	if (key == 65363)
		game->player->O = angle_change(1, game->player->O);
	return (0);
}

void	coord_to_pixel(t_player *player)
{
	player->posx = (player->startx * 100) + 50;
	player->posy = (player->starty * 100) + 50;
}

float	spawn_angle(char dir)
{
	if (dir == 'W')
		return (0.0001);
	else if (dir == 'N')
		return (M_PI / 2);
	else if (dir == 'E')
		return (M_PI);
	else if (dir == 'S')
		return (3 * M_PI);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_init_game();
	if (argc != 2)
		ft_printerror("Wrong number of arguments!", game);
	if (ft_get_paths(argv[1], game))
		ft_printerror("Missing path for one of textures!", game);	
	ft_get_map_data(argv[1], game);
	game->map2d = (char **)malloc(sizeof(char *) * (game->grid_h + 1));
	if (!game->map2d)
		ft_free_exit(game);
	if (!ft_get_2dmap(argv[1], game))
		ft_printerror("Map is not surrounded by walls!", game);
	if (!ft_get_player_position(game))
		ft_printerror("Wrong number of player starting positions!", game);
	/*g_player = malloc(sizeof(t_player));
	// **** call player_init function to feed the following info into g_player, to be read from .cub file **** //
	g_player->startx = 4;
	g_player->starty = 4;
	g_player->start_dir = 'E';*/
	coord_to_pixel(game->player);
	game->player->O = spawn_angle(game->player->start_dir);
	game->ptrs->mlx = mlx_init();
	game->ptrs->win = mlx_new_window(game->ptrs->mlx, 500, 500, "fdf");
	mlx_loop_hook(game->ptrs->mlx, cast_rays, game);
	mlx_hook(game->ptrs->win, 2, 1, deal_key, game);
	mlx_hook(game->ptrs->win, 33, 32, ft_close_clean, game);
	mlx_loop(game->ptrs->mlx);
}
