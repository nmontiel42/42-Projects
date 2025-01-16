/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:13:11 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/29 16:13:11 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	map_min_tiles(char **map)
{
	int	i;
	int	j;
	int	n_enex;
	int	n_collec;

	i = 0;
	n_enex = 0;
	n_collec = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P')
				n_enex++;
			if (map[i][j] == 'C')
				n_collec++;
			j++;
		}
		i++;
	}
	if (n_enex != 2 || n_collec < 1)
		return (FALSE);
	return (TRUE);
}

int	map_wall_is_closed(char **map)
{
	size_t	i;
	size_t	o;
	size_t	len;

	len = 0;
	i = 0;
	o = 0;
	while (map[len])
		len++;
	len--;
	while (i < ft_strlen(map[0]) && map[0][i] == '1' && map[len][i] == '1')
		i++;
	i--;
	while (o < len && map[o][0] == '1' && map[o][i] == '1')
		o++;
	while (i > 0 && map[len][i] == '1')
		i--;
	if (i == 0 && o == len)
		return (TRUE);
	return (FALSE);
}

int	map_checker(char **map)
{
	if (map_empty(map) == FALSE)
		return (ft_printf("Error\nThe map is empty\n"), 1);
	if (map_rect(map) == FALSE)
		return (ft_printf("Error\nThe map is not rectangle\n"), 1);
	if (map_components(map) == FALSE)
		return (ft_printf("Error\nThe map has the wrong components\n"), 1);
	if (map_wall_is_closed(map) == FALSE)
		return (ft_printf("Error\nThe wall is not closed\n"), 1);
	if (map_min_tiles(map) == FALSE)
		return (ft_printf("Error\nYou dont have the correct components\n"),
			1);
	return (TRUE);
}
