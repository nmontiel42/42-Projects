/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:12:58 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/29 16:12:58 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	map_empty(char **map)
{
	if (map[0])
		return (TRUE);
	return (FALSE);
}

int	map_rect(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

int	map_components(char **map)
{
	int	i;
	int	o;

	i = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (!(map[i][o] == '1' || map[i][o] == '0' || map[i][o] == 'P'
				|| map[i][o] == 'E' || map[i][o] == 'C'))
				return (FALSE);
			else
				o++;
		}
		i++;
	}
	return (TRUE);
}
