/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:46:37 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/28 16:28:46 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	*initial_pos(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_fill_map(t_game *game, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= game->mcolumn || y > game->mline
			|| game->map2[y][x] == '1' || game->map2[y][x] == 'X'))
	{
		game->map2[y][x] = 'X';
		flood_fill_map(game, y + 1, x);
		flood_fill_map(game, y - 1, x);
		flood_fill_map(game, y, x + 1);
		flood_fill_map(game, y, x - 1);
	}
}

int	check_flood_map(char **map)
{
	int	i;
	int	o;

	i = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (!(map[i][o] == '1' || map[i][o] == '0'
				|| map[i][o] == 'X'))
				return (FALSE);
			o++;
		}
		i++;
	}
	return (TRUE);
}

int	path_is_valid(t_game *game, char *fd)
{
	int	*pos;

	game->map2 = read_map(fd);
	pos = initial_pos(game->map2);
	flood_fill_map(game, pos[0], pos[1]);
	if (check_flood_map(game->map2) == FALSE)
	{
		free(pos);
		freemap(game->map2);
		return (ft_printf("Error\nThe path is not valid\n"), FALSE);
	}
	free(pos);
	freemap(game->map2);
	return (TRUE);
}
