/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:21 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 22:00:17 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sort_three_nodes(t_stack **stack_a)
{
	int	n_0;
	int	n_1;
	int	n_2;

	n_0 = (*stack_a)->nbr;
	n_1 = (*stack_a)->next->nbr;
	n_2 = (*stack_a)->next->next->nbr;
	if (n_0 < n_2 && n_1 > n_2)
		return (rra(stack_a), sa(stack_a));
	else if (n_0 < n_1 && n_0 > n_2)
		return (rra(stack_a));
	else if (n_0 > n_1 && n_0 < n_2)
		return (sa(stack_a));
	else if (n_0 > n_1 && n_1 > n_2)
		return (sa(stack_a), rra(stack_a));
	else if (n_0 > n_2 && n_2 > n_1)
		return (ra(stack_a));
	return (SUCCESS);
}

int	sort_stacks(t_stack **s_a)
{
	t_stack	*s_b;

	s_b = NULL;
	if (s_a == NULL)
		return (ERROR);
	if (ft_lstsize(*s_a) > 3)
		prepare_stacks(s_a, &s_b);
	else if (ft_lstsize(*s_a) <= 2)
	{
		if (ft_lstsize(*s_a) == 2 && (*s_a)->nbr > (*s_a)->next->nbr)
			return (sa(s_a));
		return (SUCCESS);
	}
	while (ft_lstsize(*s_a) > 3)
		move_node_min_ops(s_a, &s_b);
	sort_three_nodes(s_a);
	push_at_correct_position(s_a, &s_b);
	return (SUCCESS);
}
