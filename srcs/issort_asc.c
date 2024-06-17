/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort_asc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:05:14 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/16 20:02:05 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	issort_asc(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (false);
		lst = lst->next;
	}
	return (true);
}
