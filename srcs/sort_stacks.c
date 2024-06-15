/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:21 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/15 16:32:01 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_stacks(t_stack **stack_a)
{
	t_stack	**stack_b;

	stack_b = NULL;
	if (stack_a == NULL)
		return (ERROR);
	// FIXME: debug sa only
	//pb(stack_a, stack_b);
	sa(stack_a);
	sb(stack_b);
	rb(stack_b);
	ra(stack_a);
	return (SUCCESS);
}
