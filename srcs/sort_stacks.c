/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:21 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/15 19:31:18 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_stacks(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_a == NULL)
		return (ERROR);
	// FIXME: debug sa only
	pb(stack_a, &stack_b);
	pb(stack_a, &stack_b);
	pb(stack_a, &stack_b);
	sa(stack_a);
	sb(&stack_b);
	rb(&stack_b);
	pa(stack_a, &stack_b);
	ra(stack_a);
	rra(stack_a);
	stack_b = ft_lsthead(stack_b);
	ft_printf("---b: Print Nodes:\n");
	if (stack_b != NULL)
	{
		while (stack_b->next)
		{
			ft_printf("%d index'nbr is %d.\n", stack_b->index, stack_b->nbr);
			stack_b = stack_b->next;
		}
		ft_printf("End node: %d index'nbr is %d.\n", stack_b->index, stack_b->nbr);
		ft_printf("---b:END \n");
	}
	stack_b = ft_lsthead(stack_b);
	ft_printf("free list b is %d : 0 is SUCCESS\n", ft_lstclear(&stack_b));
	return (SUCCESS);
}
