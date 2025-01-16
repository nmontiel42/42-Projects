/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:14 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/08 16:42:04 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

char	**check_arguments(int argc, char **argv)
{
	char	**str;

	if (argc < 2)
		exit(1);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (str == NULL)
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		check(str, 0);
		return (str);
	}
	else
	{
		check(argv + 1, 0);
		return (argv + 1);
	}
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*void	ft_leaks(void)
{
	system("leaks -q checker");
}*/

//atexit(ft_leaks);

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**str;
	int		i;

	start_program(&stack_a, &stack_b);
	str = check_arguments(argc, argv);
	i = 0;
	while (str[i] != NULL)
	{
		if (!create_list_checker(str[i], stack_a))
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		i++;
	}
	checker(stack_a, stack_b);
	final_check(stack_a, stack_b);
	if (argc == 2)
		free_str(str);
	return (free_stack2(stack_a), free_stack2(stack_b), 0);
}
