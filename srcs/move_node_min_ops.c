/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_min_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:01:04 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 22:02:53 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_abs(int x)
{
	if (x > 0)
		return (-x);
	else
		return (x);
}

static void	replace_lowercost(int *c_a, int *c_b, int tmp_a, int tmp_b)
{
	int	min_c;
	int	min_tmp;

	if (ft_abs(*c_a) <= ft_abs(*c_b))
		min_c = ft_abs(*c_a);
	else
		min_c = ft_abs(*c_b);
	if (ft_abs(tmp_a) <= ft_abs(tmp_b))
		min_tmp = ft_abs(tmp_a);
	else
		min_tmp = ft_abs(tmp_b);
	if (min_tmp > min_c)
	{
		*c_a = tmp_a;
		*c_b = tmp_b;
	}
	return ;
}

static void	rotate_double(t_stack **s_a, t_stack **s_b, int *c_a, int *c_b)
{
	while (*c_a > 0 && *c_b > 0)
	{
		rr(s_a, s_b);
		(*c_a)--;
		(*c_b)--;
	}
	while (*c_a < 0 && *c_b < 0)
	{
		rrr(s_a, s_b);
		(*c_a)++;
		(*c_b)++;
	}
}

static void	rotate_single(t_stack **s_a, t_stack **s_b, int *c_a, int *c_b)
{
	if (*c_a > 0)
	{
		while ((*c_a)-- > 0)
			ra(s_a);
	}
	else
	{
		while ((*c_a)++ < 0)
			rra(s_a);
	}
	if ((*c_b) > 0)
	{
		while ((*c_b)-- > 0)
			rb(s_b);
	}
	else
	{
		while ((*c_b)++ < 0)
			rrb(s_b);
	}
}

int	move_node_min_ops(t_stack **s_a, t_stack **s_b)
{
	int		cost_a;
	int		cost_b;
	t_stack	*current_a;
	t_stack	*tgt_b;

	cost_a = INT_MAX;
	cost_b = INT_MAX;
	current_a = *s_a;
	tgt_b = NULL;
	while (current_a)
	{
		tgt_b = get_target_node_b(&current_a, s_b);
		replace_lowercost(&cost_a, &cost_b, get_cost_to_head(current_a),
			get_cost_to_head(tgt_b));
		current_a = current_a->next;
	}
	rotate_double(s_a, s_b, &cost_a, &cost_b);
	rotate_single(s_a, s_b, &cost_a, &cost_b);
	return (pb(s_a, s_b));
}
