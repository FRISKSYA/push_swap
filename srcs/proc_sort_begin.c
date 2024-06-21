/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_sort_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:35:34 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/21 19:26:44 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	prepare_stacks(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		pb(stack_a, stack_b);
	return (SUCCESS);
}
