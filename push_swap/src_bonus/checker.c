/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:34:45 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 11:32:15 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

int	instructions(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	if (strcmp(msg, "sa\n") == 0)
		return (make_sa_new(stack_a), 0);
	else if (strcmp(msg, "sb\n") == 0)
		return (make_sb_new(stack_b), 0);
	else if (strcmp(msg, "ss\n") == 0)
		return (make_ss_new(stack_a, stack_b), 0);
	else if (strcmp(msg, "ra\n") == 0)
		return (make_ra_new(stack_a), 0);
	else if (strcmp(msg, "rb\n") == 0)
		return (make_rb_new(stack_b), 0);
	else if (strcmp(msg, "rr\n") == 0)
		return (make_rr_new(stack_a, stack_b), 0);
	else if (strcmp(msg, "pa\n") == 0)
		return (make_pa_new(stack_a, stack_b), 0);
	else if (strcmp(msg, "pb\n") == 0)
		return (make_pb_new(stack_a, stack_b), 0);
	else if (strcmp(msg, "rra\n") == 0)
		return (make_rra_new(stack_a), 0);
	else if (strcmp(msg, "rrb\n") == 0)
		return (make_rrb_new(stack_b), 0);
	else if (strcmp(msg, "rrr\n") == 0)
		return (make_rrr_new(stack_a, stack_b), 0);
	return (ft_printf("ERROR\n"), 1);
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*msg;

	msg = get_next_line(0);
	while (msg)
	{
		if (instructions(stack_a, stack_b, msg) == 1)
			exit(1);
		free(msg);
		msg = get_next_line(0);
	}
}

void	start_program(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_a == NULL)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	**stack_a = NULL;
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_b == NULL)
	{
		free(*stack_a);
		ft_printf("ERROR\n");
		exit(1);
	}
	**stack_b = NULL;
}

void	final_check(t_stack **stack_a, t_stack **stack_b)
{
	(void) stack_b;
	if (!is_sorted2(stack_a) && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
