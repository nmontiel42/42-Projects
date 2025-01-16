/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:37:13 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/29 12:01:49 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	keys_and_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		up_movement(game);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		down_movement(game);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		right_movement(game);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		left_movement(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	obt_collectable(game);
}

void	up_movement(t_game *game)
{
	if (game->map[game->img->charac->instances->y / 64 - 1]
		[game->img->charac->instances->x / 64] != '1')
	{
		game->img->charac->instances->y -= MOVES;
		game->moves++;
		ft_printf("Nº de movimientos: %i\n", game->moves);
	}
}

void	down_movement(t_game *game)
{
	if (game->map[game->img->charac->instances->y / 64 + 1]
		[game->img->charac->instances->x / 64] != '1')
	{
		game->img->charac->instances->y += MOVES;
		game->moves++;
		ft_printf("Nº de movimientos: %i\n", game->moves);
	}
}

void	right_movement(t_game *game)
{
	if (game->map[game->img->charac->instances->y / 64]
		[game->img->charac->instances->x / 64 + 1] != '1')
	{
		game->img->charac->instances->x += MOVES;
		game->moves++;
		ft_printf("Nº de movimientos: %i\n", game->moves);
	}
}

void	left_movement(t_game *game)
{
	if (game->map[game->img->charac->instances->y / 64]
		[game->img->charac->instances->x / 64 - 1] != '1')
	{
		game->img->charac->instances->x -= MOVES;
		game->moves++;
		ft_printf("Nº de movimientos: %i\n", game->moves);
	}
}
