/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:36:09 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 21:51:49 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new_node;
		return (SUCCESS);
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_node;
		new_node->prev = last;
		return (SUCCESS);
	}
}
//
//#include <stdio.h>
//#include <stdlib.h>
//
// void print_list(t_stack *lst)
//{
//	printf("Printing list:\n");
//	while (lst)
//	{
//		printf(
//	"Node address: %p, Value: %ld, Index: %zu\n",
//	(void *)lst,
//	lst->nbr,
//	lst->index
//	);
//		lst = lst->next;
//	}
//}
//
//__attribute__((destructor))
// static void destructor() {
//	system("leaks -q a.out");
//}
//
// int main()
//{
//	t_stack *head = NULL;
//	t_stack *node1, *node2, *node3;
//
//	node1 = (t_stack *)malloc(sizeof(t_stack));
//	node2 = (t_stack *)malloc(sizeof(t_stack));
//	node3 = (t_stack *)malloc(sizeof(t_stack));
//	if (node1 == NULL || node2 == NULL || node3 == NULL)
//	{
//		perror("Failed to allocate memory");
//		return (1);
//	}
//
//	node1->nbr = 1;
//	node1->index = 1;
//	node1->next = NULL;
//	node1->prev = NULL;
//
//	node2->nbr = 2;
//	node2->index = 2;
//	node2->next = NULL;
//	node2->prev = NULL;
//
//	node3->nbr = 3;
//	node3->index = 3;
//	node3->next = NULL;
//	node3->prev = NULL;
//
//	ft_lstadd_back(&head, node1);
//	ft_lstadd_back(&head, node2);
//	ft_lstadd_back(&head, node3);
//
//	printf("List after adding nodes:\n");
//	print_list(head);
//
//	ft_lstclear(&head);
//
//	return (0);
//}
