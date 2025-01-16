/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:20:26 by nmontiel          #+#    #+#             */
/*   Updated: 2023/10/30 16:01:33 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_is_digit(char **str, int i)
{
	int	o;

	while (str[i])
	{
		o = 0;
		while (str[i][o])
		{
			if (!(str[i][o] >= '0' && str[i][o] <= '9') && str[i][o] != '+'
				&& str[i][o] != '-')
				return (0);
			o++;
		}
		i++;
	}
	return (1);
}

int	str_signal(char **str, int i)
{
	char	*current_char;
	int		sign;

	if (!str[i])
		return (1);
	sign = 0;
	current_char = str[i];
	while (*current_char)
	{
		if (*current_char == '+' || *current_char == '-')
		{
			sign++;
			if (sign >= 2)
				return (0);
		}
		current_char++;
	}
	return (str_signal(str, i + 1));
}

int	str_max_min(char **str, int i)
{
	while (str[i])
	{
		if (ft_atoi(str[i]) < -2147483648 || ft_atoi(str[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	str_is_double(char **str, int i)
{
	int	num;
	int	test;
	int	j;

	while (str[i])
	{
		num = ft_atoi(str[i]);
		j = i + 1;
		while (str[j])
		{
			test = ft_atoi(str[j]);
			if (num == test)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
