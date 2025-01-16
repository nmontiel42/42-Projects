/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:13:28 by nmontiel          #+#    #+#             */
/*   Updated: 2023/09/29 16:13:28 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	initialize_game(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->mlx = mlx_init(game->mline, game->mcolumn, "so_long", false);
	if (!(game->mlx))
		return (FALSE);
	obt_textures(game);
	obt_image(game);
	show_map(game, game->img);
	mlx_key_hook(game->mlx, &keys_and_moves, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	freemap(game->map);
	free(game->textu);
	free(game->img);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (game == NULL)
		return (ft_printf("Error\nMemory was not allocated correctly\n"), 1);
	if (argc != 2)
		return (ft_printf("Error\nIncorrect number of parameters\n"), 1);
	if (check_map_name(argv[1]) == FALSE)
		return (ft_printf("Error\nInvalid file extension\n"), 1);
	game->map = read_map(argv[1]);
	if (!game->map)
		return (1);
	if (map_checker(game->map) == FALSE)
		return (freemap(game->map), 1);
	map_size(game, game->map);
	if (path_is_valid(game, argv[1]) == FALSE)
		return (freemap(game->map), 1);
	if (initialize_game(game) == FALSE)
	{
		free(game);
		return (FALSE);
	}
	free(game);
	return (TRUE);
}
