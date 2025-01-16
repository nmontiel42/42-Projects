/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:22:01 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/27 18:51:49 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <stdint.h>

# define B_SIZE 10000
# define MOVES	64
# define FALSE 	1
# define TRUE 	0

typedef struct s_images
{
	mlx_image_t			*wall;
	mlx_image_t			*floor;
	mlx_image_t			*charac;
	mlx_image_t			*exit1;
	mlx_image_t			*exit2;
	mlx_image_t			*collec;
}				t_images;

typedef struct s_texture
{
	mlx_texture_t		*wall;
	mlx_texture_t		*floor;
	mlx_texture_t		*charac;
	mlx_texture_t		*exit1;
	mlx_texture_t		*exit2;
	mlx_texture_t		*collec;
}				t_texture;

typedef struct s_game
{
	struct s_texture	*textu;
	struct s_images		*img;
	mlx_t				*mlx;
	char				**map;
	int					mline;
	int					mcolumn;
	int					collected;
	int					moves;
	int					i_collected;
	char				**map2;
}								t_game;

int		map_empty(char **map);
int		map_rect(char **map);
int		map_components(char **map);
int		map_wall_is_closed(char **map);
int		map_checker(char **map);
int		map_min_tiles(char **map);
int		*initial_pos(char **map);
void	flood_fill_map(t_game *game, int y, int x);
int		check_flood_map(char **map);
int		path_is_valid(t_game *game, char *fd);
int		t_collected(t_game *game);
void	erase_collectable(t_game *game);
void	obt_collectable(t_game *game);
int		obt_textures(t_game *game);
void	obt_image(t_game *game);
void	draw_map(t_game *game, t_images *img);
void	show_map(t_game *game, t_images *img);
int		initialize_game(t_game *game);
int		main(int argc, char **argv);
int		check_map_name(const char *fn);
void	freemap(char **map);
void	map_size(t_game *game, char **map);
char	**read_map(char *scripted_map);
void	up_movement(t_game *game);
void	down_movement(t_game *game);
void	right_movement(t_game *game);
void	left_movement(t_game *game);
void	keys_and_moves(mlx_key_data_t keydata, void *param);

#endif
