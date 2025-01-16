/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:08:16 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/28 12:00:03 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	erase_collectable(t_game *game)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = game->i_collected;
	while (i < cnt)
	{
		if (((game->img->collec->instances[i].y
					== game->img->charac->instances->y)
				&& (game->img->collec->instances[i].x
					== game->img->charac->instances->x))
			&& game->img->collec->instances[i].enabled == true)
		{
			cnt--;
			game->img->collec->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	obt_collectable(t_game *game)
{
	if (game->map[game->img->charac->instances->y / 64]
		[game->img->charac->instances->x / 64] == 'C')
	{
		erase_collectable(game);
		game->map[game->img->charac->instances->y / 64]
		[game->img->charac->instances->x / 64] = '0';
		game->collected++;
		if (game->collected == game->i_collected)
			game->img->exit1->instances->enabled = false;
	}
	if (game->map[game->img->charac->instances->y / 64]
		[game->img->charac->instances->x / 64] == 'E')
	{
		if (game->collected == game->i_collected)
			mlx_close_window(game->mlx);
	}
}
