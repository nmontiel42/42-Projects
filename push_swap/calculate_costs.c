/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:34:11 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 16:00:31 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_cheap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		actions_a;
	int		actions_b;
	int		cheap_cost;

	if (*stack_b == NULL)
		return ;
	cheap_cost = 2147483647;
	temp = *stack_b;
	while (temp)
	{
		if (my_abs(temp->actions_a) + my_abs(temp->actions_b)
			< my_abs(cheap_cost))
		{
			cheap_cost = my_abs(temp->actions_a) + my_abs(temp->actions_b);
			actions_a = temp->actions_a;
			actions_b = temp->actions_b;
		}
		temp = temp->next;
	}
	make_move(stack_a, stack_b, actions_a, actions_b);
}

void	cal_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cpy_b;
	int		size_a;
	int		size_b;

	cpy_b = *stack_b;
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	while (cpy_b)
	{
		if (cpy_b->position > size_b / 2)
			cpy_b->actions_b = (size_b - cpy_b->position) * -1;
		else
			cpy_b->actions_b = cpy_b->position;
		if (cpy_b->destinal_pos > size_a / 2)
			cpy_b->actions_a = (size_a - cpy_b->destinal_pos) * -1;
		else
			cpy_b->actions_a = cpy_b->destinal_pos;
		cpy_b = cpy_b->next;
	}
}
