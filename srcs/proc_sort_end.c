/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_sort_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:35:15 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/18 16:05:56 by kfukuhar         ###   ########.fr       */
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

int	push_at_correct_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tgt_node;

	tgt_node = NULL;
	while (ft_lstsize(*stack_b) > 0)
	{
		tgt_node = get_target_node_a(stack_a, stack_b);
		rotate_stack_to_target(stack_a, tgt_node);
		pa(stack_a, stack_b);
	}
	if (issort_asc(ft_lsthead(*stack_a)) == true)
		return (SUCCESS);
	while ((*stack_a)->nbr < (*stack_a)->next->nbr)
		ra(stack_a);
	return (ra(stack_a));
}
