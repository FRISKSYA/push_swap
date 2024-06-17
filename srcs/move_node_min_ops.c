/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_min_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:01:04 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/17 17:59:14 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	get_min_cost_node_index(t_stack **s_a, t_stack **s_b)
{
	size_t	*cost;

	cost = NULL;
	ft_lstsize(*s_b);
	return ((*s_a)->index);
}

static int	move_node(t_stack **s_a, t_stack **s_b, size_t i)
{
	i++;
	ft_lstsize(*s_a);
	ft_lstsize(*s_b);
	return (pb(s_a, s_b));
}

// NOTE: calculate move cost and move the cheapest node
int	move_node_min_ops(t_stack **stack_a, t_stack **stack_b)
{
	size_t	i;

	i = 0;
	i = get_min_cost_node_index(stack_a, stack_b);
	return (move_node(stack_a, stack_b, i));
}
