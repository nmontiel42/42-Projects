/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:13:43 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 16:02:28 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_leaks(void)
{
	system("leaks -q push_swap");
}*/

int	space(char **str)
{
	int	o;

	o = 0;
	while (str[1][o])
	{
		if (str[1][o] != ' ')
			return (1);
		o++;
	}
	return (0);
}
//atexit(ft_leaks);, antes de if (argc == 1);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	if (argc == 1)
		return (0);
	if (argv[1][0] == '\0' || !space(argv))
		return (ft_printf("ERROR\n"), 0);
	stack_b = NULL;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!check(str, 0))
			return (free_str(str), 0);
		stack_a = create_list(str, 0);
		free_str(str);
	}
	else if (argc > 2)
	{
		if (!check(argv, 1))
			return (0);
		stack_a = create_list(argv, 1);
	}
	order_checker(&stack_a, &stack_b);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
