/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_sort_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:35:15 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/17 18:41:45 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*find_target_node(t_stack *cur_a, t_stack *s_a, long b_val)
{
	t_stack	*tgt;
	long	closest_larger_value;

	tgt = NULL;
	closest_larger_value = LONG_MAX;
	while (cur_a && (cur_a != s_a || !tgt))
	{
		if (cur_a->nbr > b_val && cur_a->nbr < closest_larger_value)
		{
			closest_larger_value = cur_a->nbr;
			tgt = cur_a;
		}
		cur_a = cur_a->next;
	}
	return (tgt);
}

static t_stack	*find_min_node(t_stack *cur_a, t_stack *s_a)
{
	t_stack	*tgt;
	long	min_nbr;

	tgt = NULL;
	min_nbr = s_a->nbr;
	cur_a = cur_a->next;
	while (cur_a && cur_a != s_a)
	{
		if (cur_a->nbr < min_nbr)
		{
			min_nbr = cur_a->nbr;
			tgt = cur_a;
		}
		cur_a = cur_a->next;
	}
	return (tgt);
}

static t_stack	*get_target_node(t_stack **s_a, t_stack **s_b)
{
	long int	b_nbr;
	t_stack		*current_a;
	t_stack		*tgt;

	if (!s_a || !s_b || !*s_b)
		return (NULL);
	b_nbr = (*s_b)->nbr;
	current_a = *s_a;
	tgt = NULL;
	tgt = find_target_node(current_a, *s_a, b_nbr);
	if (!tgt)
		tgt = find_min_node(current_a, *s_a);
	return (tgt);
}

int	push_at_correct_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tgt_node;

	tgt_node = NULL;
	while (ft_lstsize(*stack_b) > 0)
	{
		tgt_node = get_target_node(stack_a, stack_b);
		while (tgt_node && tgt_node != *stack_a)
			ra(stack_a);
		pa(stack_a, stack_b);
	}
	if (issort_asc(ft_lsthead(*stack_a)) == true)
		return (SUCCESS);
	while ((*stack_a)->nbr < (*stack_a)->next->nbr)
		ra(stack_a);
	return (ra(stack_a));
}
