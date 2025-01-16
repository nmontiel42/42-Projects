/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:38:02 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 11:20:16 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_actions(t_stack **stack_a, t_stack **stack_b,
			int *actions_a, int *actions_b)
{
	while (*actions_a || *actions_b)
	{
		if (*actions_a > 0)
		{
			make_ra(stack_a);
			(*actions_a)--;
		}
		else if (*actions_a < 0)
		{
			make_rra(stack_a);
			(*actions_a)++;
		}
		else if (*actions_b > 0)
		{
			make_rb(stack_b);
			(*actions_b)--;
		}
		else if (*actions_b < 0)
		{
			make_rrb(stack_b);
			(*actions_b)++;
		}
	}
}

void	do_both_moves(t_stack **stack_a, t_stack **stack_b,
				int *actions_a, int *actions_b)
{
	if (actions_a < 0 && actions_b < 0)
	{
		while (*actions_a < 0 && *actions_b < 0)
		{
			make_rrr(stack_a, stack_b);
			(*actions_a)++;
			(*actions_b)++;
		}
	}
	else if (actions_a > 0 && actions_b > 0)
	{
		while (*actions_a > 0 && *actions_b > 0)
		{
			make_rr(stack_a, stack_b);
			(*actions_a)--;
			(*actions_b)--;
		}
	}
}

void	make_move(t_stack **stack_a, t_stack **stack_b,
				int actions_a, int actions_b)
{
	do_both_moves(stack_a, stack_b, &actions_a, &actions_b);
	make_actions(stack_a, stack_b, &actions_a, &actions_b);
	make_pa(stack_a, stack_b);
}
