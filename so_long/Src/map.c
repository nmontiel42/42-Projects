/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:13:35 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/29 16:13:35 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	t_collected(t_game *game)
{
	int	total;
	int	i;
	int	o;

	total = 0;
	i = 0;
	while (game->map[i])
	{
		o = 0;
		while (game->map[i][o])
		{
			if (game->map[i][o] == 'C')
				total++;
			o++;
		}
		i++;
	}
	return (total);
}

int	check_map_name(const char *fn)
{
	int	i;

	i = ft_strlen(fn) - 1;
	if (fn[i] != 'r' || fn[i - 1] != 'e'
		|| fn[i - 2] != 'b'
		|| fn[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}

void	freemap(char **map)
{
	int	i;

	i = -1;
	while (map[i++])
		free(map[i]);
	free(map);
}

void	map_size(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->i_collected = t_collected(game);
	game->mline = ft_strlen(map[0]) * 64;
	while (map[i])
		i++;
	game->mcolumn = i * 64;
}

char	**read_map(char *scripted_map)
{
	int		fd;
	int		i;
	char	*temp_map;
	char	**map;

	i = 0;
	temp_map = ft_calloc(B_SIZE, sizeof(char));
	if (!temp_map)
		return (0);
	fd = open(scripted_map, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	i = read(fd, temp_map, B_SIZE);
	if (i == -1 || i == 0)
	{
		free(temp_map);
		return (0);
	}
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}
