/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:38:46 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/13 14:37:54 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int		len;

	if (lst == NULL)
		return (0);
	len = 1;
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
//
//#include <stdio.h>   // printf
//#include <stdlib.h>  // malloc, free
//
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
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}
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
//    node1->next = NULL;
//
//    node2->nbr = 2;
//    node2->index = 2;
//    node2->next = NULL;
//
//    node3->nbr = 3;
//    node3->index = 3;
//    node3->next = NULL;
//
//    head = node1;
//    node1->next = node2;
//    node2->next = node3;
//
//    printf("List contents:\n");
//    print_list(head);
//
//    int size = ft_lstsize(head);
//    printf("List size: %d\n", size);
//
//    free(node1);
//    free(node2);
//    free(node3);
//
//    return 0;
//}
