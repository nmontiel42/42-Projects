/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:37:55 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 16:21:06 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	push;

	size = stack_size(*stack_a);
	push = 0;
	while (push < size / 2 && size > 6)
	{
		if ((*stack_a)->index <= size / 2)
		{
			make_pb(stack_a, stack_b);
			push++;
		}
		else
			make_ra(stack_a);
	}
	while (push < size - 3)
	{
		make_pb(stack_a, stack_b);
		push++;
	}
}

void	sort_three_numbers(t_stack **stack)
{
	int	high;

	high = highest_index(*stack);
	if ((*stack)->index == high)
		make_ra(stack);
	else if ((*stack)->next->index == high)
		make_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		make_sa(stack);
}

void	order_checker(t_stack **stack_a, t_stack **stack_b)
{
	int	list_len;

	if (is_sorted(*stack_a))
		return ;
	list_len = stack_size(*stack_a);
	set_index_stack_a(*stack_a, (list_len + 1));
	if (list_len == 1)
		return ;
	if (list_len == 2)
		make_sa(stack_a);
	else if (list_len == 3)
		sort_three_numbers(stack_a);
	else
		first_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	sort_stack_a(t_stack **stack_a)
{
	int	min;
	int	size;

	min = min_index(stack_a);
	size = stack_size(*stack_a);
	if (min > size / 2)
	{
		min = size - min;
		while (min > 0)
		{
			make_rra(stack_a);
			min--;
		}
	}
	else
	{
		while (min > 0)
		{
			make_ra(stack_a);
			min--;
		}
	}
}

void	first_sort(t_stack **stack_a, t_stack **stack_b)
{
	move_to_b(stack_a, stack_b);
	sort_three_numbers(stack_a);
	while (*stack_b)
	{
		set_target(stack_a, stack_b);
		cal_cost(stack_a, stack_b);
		cal_cheap(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack_a(stack_a);
}
