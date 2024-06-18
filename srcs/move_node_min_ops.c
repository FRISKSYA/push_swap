/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_min_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:01:04 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/18 18:04:06 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//static size_t	get_min_cost_node_index(t_stack **s_a, t_stack **s_b)
//{
//	size_t	cost;
//
//	cost = 0;
//	ft_lstsize(*s_b);
//	return ((*s_a)->index);
//}
//
//static int	move_node(t_stack **s_a, t_stack **s_b, size_t i)
//{
//	i++;
//	ft_lstsize(*s_a);
//	ft_lstsize(*s_b);
//	return (pb(s_a, s_b));
//}
//
//// NOTE: calculate move cost and move the cheapest node
//int	move_node_min_ops(t_stack **stack_a, t_stack **stack_b)
//{
//	size_t	i;
//
//	i = 0;
//	i = get_min_cost_node_index(stack_a, stack_b);
//	return (move_node(stack_a, stack_b, i));
//}

static long int	get_cost_to_head(t_stack **lst, t_stack *lst_node)
{
	t_stack		*head;
	t_stack		*current;
	long int	cost;
	size_t		size_lst;

	head = *lst;
	current = head;
	cost = 0;
	size_lst = ft_lstsize(*lst);
	while (current != lst_node)
	{
		cost++;
		current = current->next;
	}
	if (cost > (long int)(size_lst / 2))
		return (cost - (long int)size_lst);
	else
		return (cost);
}

static long int	get_count_rotate(t_stack **s_a, t_stack **s_b, t_stack *cur_a,
		t_stack *tgt)
{
	long int	rotate_a;
	long int	rotate_b;

	rotate_a = get_cost_to_head(s_a, cur_a);
	rotate_b = get_cost_to_head(s_b, tgt);
	if (rotate_a == 0 && rotate_b == 0)
		return (0);
	else if ((rotate_a >= 0 && rotate_b <= 0) || (rotate_a <= 0
			&& rotate_b >= 0))
		return (LONG_MAX);
	else
		return (rotate_a);
}

// TODO: just draft
#include <stdio.h>
int	move_node_min_ops(t_stack **s_a, t_stack **s_b)
{
	long int	count_rotate;
	long int	tmp;
	t_stack		*current_a;
	t_stack		*tgt_node;

	count_rotate = LONG_MAX;
	current_a = *s_a;
	tgt_node = NULL;
	while (current_a)
	{
		// 現在のaノードに対するbの中のターゲットノードを取得
		tgt_node = get_target_node_b(&current_a, s_b);
		if (tgt_node)
			printf("current_a->nbr: %ld, tgt_node->nbr: %ld.\n", current_a->nbr, tgt_node->nbr);
		else
			printf("current_a->nbr: %ld, tgt_node is null.\n", current_a->nbr);
		tmp = get_count_rotate(s_a, s_b, current_a, tgt_node);
		if (count_rotate > tmp)
			count_rotate = tmp;
		current_a = current_a->next;
	}
	printf("count_rotate_ 1: %ld\n", count_rotate);
	if (count_rotate == LONG_MAX)
		return (pb(s_a, s_b));
	else if (count_rotate > 0)
	{
		while (count_rotate-- > 0)
			rr(s_a, s_b);
	}
	else
	{
		while (count_rotate++ < 0)
			rrr(s_a, s_b);
	}
	tgt_node = get_target_node_b(s_a, s_b);
	count_rotate = get_cost_to_head(s_b, tgt_node);
	printf("count_rotate_ 2: %ld\n", count_rotate);
	if (count_rotate == 0)
		return (pb(s_a, s_b));
	while (count_rotate-- > 0)
	{
		rb(s_b);
		return (pb(s_a, s_b));
	}
	while (count_rotate++ < 0)
	{
		rrb(s_b);
		return (pb(s_a, s_b));
	}
	return (SUCCESS);
}
