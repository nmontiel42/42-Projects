/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:15:05 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/08 17:14:02 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	rotate2(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_size(*stack) > 1)
	{
		first = *stack;
		last = *stack;
		*stack = first->next;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	make_ra_new(t_stack **stack_a)
{
	rotate2(stack_a);
}

void	make_rb_new(t_stack **stack_b)
{
	rotate2(stack_b);
}

void	make_rr_new(t_stack **stack_a, t_stack **stack_b)
{
	rotate2(stack_a);
	rotate2(stack_b);
}
