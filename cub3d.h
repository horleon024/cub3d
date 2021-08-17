/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:11:54 by lhorefto          #+#    #+#             */
/*   Updated: 2021/08/13 15:08:36 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# define A 97
# define W 119
# define D 100
# define S 115
# define BLACK 0xFF000000
# define ESC 65307
# define PIX 256
# define SCREENWIDTH 750
# define SCREENHEIGHT 500

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		linelength;
	int		endian;
	int		width;
	int		height;
	char	*path;
}			t_img;

typedef struct s_ptrs
{
	void	*mlx;
	void	*win;
}			t_ptrs;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	direction;
}				t_player;

typedef struct s_ray
{
	double	camera_x;
	double	camera_y;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}			t_ray;

typedef struct s_game
{
	t_img			*img;
	int				floor;
	int				ceil;
	t_img			*no_wall;
	t_img			*so_wall;
	t_img			*ea_wall;
	t_img			*we_wall;
	t_ptrs			*ptrs;
	t_player		*player;
	t_ray			*ray;
	double			time;
	double			old_time;
	char			**map2d;
	int				map_lines;
	int				map_line_length;
}					t_game;

t_game	*ft_init_game(void);
void	ft_free_exit(t_game *game);
int		ft_close_clean(t_game *game);
void	ft_printerror(char *msg, t_game *game);
bool	ft_get_paths(char *path, t_game *game);
void	ft_get_map_data(char *path, t_game *game);
bool	ft_get_2dmap(char *path, t_game *game);
bool	ft_map_is_valid(char **map, int lines);
int		ft_convert_rgb(char	*rgb);
void	ft_start_game(t_game *game);
bool	ft_get_player_position(t_game *game);


#endif