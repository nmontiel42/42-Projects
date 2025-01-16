/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:16:39 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/08 14:23:39 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_stack(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

t_stack	*pen_stack(t_stack *lst)
{
	while (lst && lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void	new_last_element(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (stack && new)
	{
		current = *stack;
		if (!current)
			*stack = new;
		else
		{
			while (current->next)
				current = current->next;
			current->next = new;
		}
	}
}

t_stack	*new_node(int num)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = num;
	stack->position = -1;
	stack->destinal_pos = -1;
	stack->index = 0;
	stack->actions_a = -1;
	stack->actions_b = -1;
	stack->next = NULL;
	return (stack);
}

t_stack	*create_list(char **argv, int i)
{
	t_stack	*new;
	int		num;

	new = NULL;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		new_last_element(&new, new_node(num));
		i++;
	}
	return (new);
}
