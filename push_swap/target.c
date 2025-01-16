/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:41:15 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 16:27:48 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack **stack_a)
{
	t_stack	*temp;
	int		low_index;
	int		low_pos;

	temp = *stack_a;
	low_index = 2147483647;
	set_pos(stack_a);
	low_pos = temp->position;
	while (temp)
	{
		if (temp->index < low_index)
		{
			low_index = temp->index;
			low_pos = temp->position;
		}
		temp = temp->next;
	}
	return (low_pos);
}

int	target_to_b(t_stack **stack_a, int b_index,
		int target_index, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > b_index && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (target_index != 2147483647)
		return (target_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	set_pos(stack_a);
	set_pos(stack_b);
	while (temp)
	{
		temp->destinal_pos = target_to_b(stack_a, temp->index, 2147483647, 0);
		temp = temp->next;
	}
}
