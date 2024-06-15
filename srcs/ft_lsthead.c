/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsthead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:15:16 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/15 12:20:36 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lsthead(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
