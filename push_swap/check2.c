/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:00:16 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/07 11:48:05 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check2(char **str, int i)
{
	if (!str_is_digit(str, i))
	{
		ft_printf("ERROR\nIt's not all digits\n");
		exit(1);
	}
	if (!str_signal(str, i))
	{
		ft_printf("ERROR\nDouble sign or followed signs\n");
		exit(1);
	}
}

int	check(char **str, int i)
{
	check2(str, i);
	if (!str_max_min(str, i))
	{
		ft_printf("ERROR\nMaximus and minimous\n");
		exit(1);
	}
	if (!str_is_double(str, i))
	{
		ft_printf("ERROR\nThere is a repeated number\n");
		exit(1);
	}
	return (1);
}
