/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_sort_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:35:15 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 21:59:49 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_stack_to_target(t_stack **stack_a, t_stack *target_node)
{
	size_t		size_a;
	size_t		pos_tgt;
	t_stack		*cur;

	if (target_node == NULL)
		return ;
	size_a = ft_lstsize(*stack_a);
	pos_tgt = 0;
	cur = *stack_a;
	while (cur != target_node)
	{
		cur = cur->next;
		pos_tgt++;
	}
	if (pos_tgt <= size_a / 2)
	{
		while (*stack_a != target_node)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != target_node)
			rra(stack_a);
	}
}

void	push_at_correct_position(t_stack **s_a, t_stack **s_b)
{
	t_stack		*tgt_node;
	t_stack		*border;
	int			count_end_rotate;

	tgt_node = NULL;
	while (ft_lstsize(*s_b) > 0)
	{
		tgt_node = get_target_node_a(s_a, s_b);
		rotate_stack_to_target(s_a, tgt_node);
		pa(s_a, s_b);
	}
	border = (ft_lsthead(*s_a))->next;
	while (border && border->prev->nbr < border->nbr)
		border = border->next;
	count_end_rotate = get_cost_to_head(border);
	if (count_end_rotate > 0)
	{
		while (count_end_rotate-- > 0)
			ra(s_a);
	}
	else
	{
		while (count_end_rotate++ < 0)
			rra(s_a);
	}
}
