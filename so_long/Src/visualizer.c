/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:37:47 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/28 12:05:45 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	obt_textures(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_texture));
	if (!game->textu)
		return (FALSE);
	game->textu->floor = mlx_load_png("./Sprites/floor.png");
	if (!game->textu->floor)
		return (FALSE);
	game->textu->wall = mlx_load_png ("./Sprites/wall.png");
	if (!game->textu->wall)
		return (FALSE);
	game->textu->charac = mlx_load_png ("./Sprites/character.png");
	if (!game->textu->charac)
		return (FALSE);
	game->textu->exit1 = mlx_load_png ("./Sprites/exit1.png");
	if (!game->textu->exit1)
		return (FALSE);
	game->textu->exit2 = mlx_load_png ("./Sprites/exit2.png");
	if (!game->textu->exit2)
		return (FALSE);
	game->textu->collec = mlx_load_png ("./Sprites/collectible.png");
	if (!game->textu->collec)
		return (FALSE);
	return (TRUE);
}

void	obt_image(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_images));
	if (!game->img)
		return ;
	game->img->floor = mlx_texture_to_image (game->mlx, game->textu->floor);
	game->img->wall = mlx_texture_to_image (game->mlx, game->textu->wall);
	game->img->charac = mlx_texture_to_image (game->mlx, game->textu->charac);
	game->img->exit1 = mlx_texture_to_image (game->mlx, game->textu->exit1);
	game->img->exit2 = mlx_texture_to_image (game->mlx, game->textu->exit2);
	game->img->collec = mlx_texture_to_image (game->mlx, game->textu->collec);
	mlx_delete_texture (game->textu->floor);
	mlx_delete_texture (game->textu->wall);
	mlx_delete_texture (game->textu->charac);
	mlx_delete_texture (game->textu->exit1);
	mlx_delete_texture (game->textu->exit2);
	mlx_delete_texture (game->textu->collec);
}

void	draw_map(t_game *game, t_images *img)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, img->floor, x * 64, y * 64);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, img->wall, x * 64, y * 64);
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, img->exit2, x * 64, y * 64);
				mlx_image_to_window(game->mlx, img->exit1, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	show_map(t_game *game, t_images *img)
{
	int	x;
	int	y;

	draw_map(game, img);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, img->collec, x * 64, y * 64);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, img->charac, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
