/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:13:30 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 11:30:41 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	swap2(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	make_sa_new(t_stack **stack_a)
{
	swap2(*stack_a);
}

void	make_sb_new(t_stack **stack_b)
{
	swap2(*stack_b);
}

void	make_ss_new(t_stack **stack_a, t_stack **stack_b)
{
	swap2(*stack_a);
	swap2(*stack_b);
}
