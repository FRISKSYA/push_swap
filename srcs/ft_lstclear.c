/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:37:45 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/13 14:37:50 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (lst == NULL)
		return (SUCCESS);
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(lst);
		(*lst) = tmp;
	}
	*lst = NULL;
	return (SUCCESS);
}
//
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}
//
//#include <stdio.h>
//void print_list(t_stack *lst)
//{
//    printf("Printing list:\n");
//    while (lst)
//    {
//        printf(
//        "Node address: %p, Value: %ld, Index: %zu\n",
//        (void *)lst,
//        lst->nbr,
//        lst->index
//        );
//        lst = lst->next;
//    }
//}
//
//int main()
//{
//    t_stack *head = NULL;
//    t_stack *node1, *node2, *node3;
//
//    node1 = (t_stack *)malloc(sizeof(t_stack));
//    node2 = (t_stack *)malloc(sizeof(t_stack));
//    node3 = (t_stack *)malloc(sizeof(t_stack));
//    if (node1 == NULL || node2 == NULL || node3 == NULL)
//    {
//        perror("Failed to allocate memory");
//        return 1;
//    }
//
//    node1->nbr = 1;
//    node1->index = 1;
//    node1->next = node2;
//    node1->prev = NULL;
//
//    node2->nbr = 2;
//    node2->index = 2;
//    node2->next = node3;
//    node2->prev = node1;
//
//    node3->nbr = 3;
//    node3->index = 3;
//    node3->next = NULL;
//    node3->prev = node2;
//
//    head = node1;
//
//    printf("Before clearing:\n");
//    print_list(head);
//
//    ft_lstclear(&head);
//
//    printf("After clearing:\n");
//    print_list(head);
//
//    return 0;
//}
