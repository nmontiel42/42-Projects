/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:50:33 by nmontiel          #+#    #+#             */
/*   Updated: 2023/11/09 16:31:11 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				position;
	int				destinal_pos;
	int				actions_a;
	int				actions_b;
	struct s_stack	*next;
}	t_stack;

//calculate_costs.c
void	cal_cheap(t_stack **stack_a, t_stack **stack_b);
void	cal_cost(t_stack **stack_a, t_stack **stack_b);

//check.c
int		str_is_double(char **str, int i);
int		str_is_digit(char **str, int i);
int		str_signal(char **str, int i);
int		str_max_min(char **str, int i);

//check2.c
void	check2(char **str, int i);
int		check(char **str, int i);

//create_list.c
t_stack	*last_stack(t_stack *lst);
t_stack	*pen_stack(t_stack *lst);
t_stack	*new_node(int num);
t_stack	*create_list(char **argv, int i);
void	new_last_element(t_stack **stack, t_stack *new);

//main.c
//void		ft_leaks(void);
int		space(char **str);
int		main(int argc, char **argv);

//moves.c
void	make_actions(t_stack **stack_a, t_stack **stack_b,
			int *actions_a, int *actions_b);
void	do_both_moves(t_stack **stack_a, t_stack **stack_b,
			int *actions_a, int *actions_b);
void	make_move(t_stack **stack_a, t_stack **stack_b,
			int actions_a, int actions_b);

//push.c
void	push(t_stack **start, t_stack **end);
void	make_pa(t_stack **stack_a, t_stack **stack_b);
void	make_pb(t_stack **stack_a, t_stack **stack_b);

//r_rotate.c
void	reverse_rotate(t_stack **stack);
void	make_rra(t_stack **stack_a);
void	make_rrb(t_stack **stack_b);
void	make_rrr(t_stack **stack_a, t_stack **stack_b);

//rotate.c
void	rotate(t_stack **stack);
void	make_ra(t_stack **stack_a);
void	make_rb(t_stack **stack_b);
void	make_rr(t_stack **stack_a, t_stack **stack_b);

//swap.c
void	swap(t_stack *stack);
void	make_sa(t_stack **stack_a);
void	make_sb(t_stack **stack_b);
void	make_ss(t_stack **stack_a, t_stack **stack_b);

//sort_nums.c
void	move_to_b(t_stack **stack_a, t_stack **stack_b);
void	sort_three_numbers(t_stack **stack);
void	sort_stack_a(t_stack **stack_a);
void	first_sort(t_stack **stack_a, t_stack **stack_b);
void	order_checker(t_stack **stack_a, t_stack **stack_b);

//target.c
int		min_index(t_stack **stack_a);
int		target_to_b(t_stack **stack_a, int b_index,
			int target_index, int target_pos);
void	set_target(t_stack **stack_a, t_stack **stack_b);

//utils.c
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack_a);
void	free_stack(t_stack **stack);
int		my_abs(int num);

//utils2.c
void	set_pos(t_stack **stack);
void	set_index_stack_a(t_stack *stack_a, int len_list);
int		highest_index(t_stack *stack);
void	free_str(char **str);

/*BONUS*/

//checker.c
int		strcmp(const char *str1, const char *str2);
int		instructions(t_stack **stack_a, t_stack **stack_b, char *msg);
void	checker(t_stack **stack_a, t_stack **stack_b);
void	start_program(t_stack ***stack_a, t_stack ***stack_b);
void	final_check(t_stack **stack_a, t_stack **stack_b);

//checker2.c
char	**check_arguments(int argc, char **argv);
int		main(int argc, char **argv);
int		is_sorted2(t_stack **stack);

//actions.c
void	make_sa_new(t_stack **stack_a);
void	make_sb_new(t_stack **stack_b);
void	make_ss_new(t_stack **stack_a, t_stack **stack_b);
void	swap2(t_stack *stack);

//actions2.c
void	rotate2(t_stack **stack);
void	make_ra_new(t_stack **stack_a);
void	make_rb_new(t_stack **stack_b);
void	make_rr_new(t_stack **stack_a, t_stack **stack_b);

//actions3.c
void	r_rotate2(t_stack **stack);
void	make_rra_new(t_stack **stack_a);
void	make_rrb_new(t_stack **stack_b);
void	make_rrr_new(t_stack **stack_a, t_stack **stack_b);

//actions4.c
void	push2(t_stack **stack_one, t_stack **stack_two);
void	make_pa_new(t_stack **stack_a, t_stack **stack_b);
void	make_pb_new(t_stack **stack_a, t_stack **stack_b);
int		create_list_checker(char *str_num, t_stack **stack);
void	free_stack2(t_stack **stack);

#endif