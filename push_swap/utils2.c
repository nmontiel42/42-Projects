/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:42:45 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 16:31:50 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stack;
	pos = 0;
	while (tmp)
	{
		tmp->position = pos++;
		tmp = tmp->next;
	}
}

void	set_index_stack_a(t_stack *stack_a, int len_list)
{
	t_stack	*list;
	t_stack	*high;
	int		num;

	while (--len_list >= 0)
	{
		list = stack_a;
		num = INT_MIN;
		high = NULL;
		while (list)
		{
			if (list->num == INT_MIN && list->index == 0)
				list->index = 1;
			if (list->num > num && list->index == 0)
			{
				num = list->num;
				high = list;
				list = stack_a;
			}
			else
				list = list->next;
		}
		if (high != NULL)
			high->index = len_list;
	}
}

int	highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
