/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:18:26 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/08 17:14:39 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	push2(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*tmp;

	if (stack_size(*stack_two) >= 1)
	{
		tmp = *stack_two;
		*stack_two = (*stack_two)->next;
		tmp->next = *stack_one;
		*stack_one = tmp;
	}
}

void	make_pa_new(t_stack **stack_a, t_stack **stack_b)
{
	push2(stack_a, stack_b);
}

void	make_pb_new(t_stack **stack_a, t_stack **stack_b)
{
	push2(stack_b, stack_a);
}

int	create_list_checker(char *str_num, t_stack **stack)
{
	int		num;
	t_stack	*new_node;

	num = ft_atoi(str_num);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	new_node->num = num;
	new_node->position = 0;
	new_node->destinal_pos = 0;
	new_node->index = 0;
	new_node->actions_a = 0;
	new_node->actions_b = 0;
	new_node->next = NULL;
	new_last_element(stack, new_node);
	return (1);
}

void	free_stack2(t_stack **stack)
{
	t_stack	*node;
	t_stack	*aux;

	node = *stack;
	while (node)
	{
		aux = node->next;
		free(node);
		node = aux;
	}
	free(stack);
}
