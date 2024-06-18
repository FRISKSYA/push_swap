/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_node_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:00:03 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/18 16:17:44 by kfukuhar         ###   ########.fr       */
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

t_stack	*get_target_node_a(t_stack **s_a, t_stack **s_b)
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

