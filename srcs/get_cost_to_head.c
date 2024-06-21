/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost_to_head.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:35:45 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/21 13:55:33 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	get_cost_to_head(t_stack *lst_node)
{
	t_stack		*head;
	t_stack		*current;
	long int	cost;
	size_t		size_lst;

	head = ft_lsthead(lst_node);
	current = head;
	cost = 0;
	size_lst = ft_lstsize(head);
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
